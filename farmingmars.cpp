#include <bits/stdc++.h>

using namespace std;

int ROOT;

// use Mo's Algorithm to sort queries into sqrt sized blocks
bool cmp(pair<pair<int,int>,int>& p1, pair<pair<int,int>,int>& p2) {
    int l1 = p1.first.first;
    int r1 = p1.first.second;

    int l2 = p2.first.first;
    int r2 = p2.first.second;

    l1 /= ROOT;
    l2 /= ROOT;

    if(l1 != l2) {
        return l1 < l2;
    }

    return r1 < r2;
}

// Delta: 1 to add, -1 to remove
void modify(int value, int delta, map<int,int>& freq, set<pair<int,int>>& maxfreq) {
    int cnt = freq[value];
    maxfreq.erase({cnt,value});
    cnt += delta;
    maxfreq.insert({cnt,value});
    freq[value] = cnt;
}

// figure out how frequent the most common value occurs
int getCntOfMax(set<pair<int,int>>& maxfreq) {
    pair<int,int> p = *maxfreq.rbegin();
    return p.first;
}

int main() {
    // Read in the PH values
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        v[i] *= 10000000;
        char c;
        int t;
        cin >> c >> t;
        v[i] += t;
    }

    // Read in the query ranges
    vector<pair<pair<int,int>,int>> queries;
    for(int i = 0; i < q; i++) {
        pair<int,int> p;
        cin >> p.first >> p.second;
        p.first--; p.second--;
        queries.push_back({p,i});
    }

    // Sort the queries so we get NlogN performance overall
    ROOT = sqrt(n);
    sort(queries.begin(),queries.end(),cmp);

    // Set up data structures
    map<int,int> freq; // maps the PH to its frequency
    set<pair<int,int>> maxfreq; // {freq,PH} (just grab the last element of ths for the max freq)
    for(auto i : v) {
        freq[i] = 0;
        maxfreq.insert({0,i});
    }

    // Initialize our l/r pointers
    int l = 0;
    int r = 0;
    modify(v[0], 1, freq, maxfreq);

    // Process queries here
    vector<bool> ans(q);
    for(auto i : queries) {
        int ql = i.first.first;
        int qr = i.first.second;

        // walk pointers outward to have the correct range
        while(l > ql) {
            l--;
            modify(v[l], 1, freq, maxfreq);
        }
        while(r < qr) {
            r++;
            modify(v[r], 1, freq, maxfreq);
        }

        // walk pointers inward to have the correct range
        while(l < ql) {
            modify(v[l], -1, freq, maxfreq);
            l++;
        }
        while(r > qr) {
            modify(v[r], -1, freq, maxfreq);
            r--;
        }

        // figure out if this range works
        int freq = getCntOfMax(maxfreq);
        bool works = freq > (qr-ql+1)/2;
        ans[i.second] = works;

        //cout << "range " << ql << " " << qr << " has freq " << freq << endl;
    }

    // print the answer
    for(auto i : ans) {
        if(i) cout << "usable" << endl;
        else cout << "unusable" << endl;
    }
}
