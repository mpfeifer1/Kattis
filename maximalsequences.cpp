#include <bits/stdc++.h>

using namespace std;

// Given start and endpoint, tell if we can connect them (including grabbing start and end)
bool works(int start, int end, vector<vector<int>>& indexes, vector<int>& query) {
    int total = 0;
    for(auto i : query) {
        auto lo = lower_bound(indexes[i].begin(), indexes[i].end(), start);
        auto hi = upper_bound(indexes[i].begin(), indexes[i].end(), end);
        total += distance(lo,hi);
    }

    int needed = (end - start) + 1;
    return total >= needed;
}

void solve(int start, vector<vector<int>>& indexes, vector<int>& query, int n) {
    sort(query.begin(), query.end());
    query.erase(unique(query.begin(), query.end()), query.end());

    int lo = start;
    int hi = n;
    int mi;

    if(!works(start, start, indexes, query)) {
        cout << 0 << endl;
        return;
    }

    while(lo+1 < hi) {
        mi = (lo+hi)/2;
        if(works(start, mi, indexes, query)) {
            lo = mi;
        }
        else {
            hi = mi;
        }
    }

    cout << lo-start+1 << endl;
}

map<int,int> compress(set<int>& s) {
    vector<int> v;
    for(auto i : s) {
        v.push_back(i);
    }
    map<int,int> conv;
    for(int i = 0; i < v.size(); i++) {
        conv[v[i]] = i;
    }
    return conv;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    set<int> s;
    for(auto& i : v) {
        cin >> i;
        s.insert(i);
    }

    map<int,int> conv = compress(s);

    vector<vector<int>> indexes(n);
    for(int i = 0; i < v.size(); i++) {
        v[i] = conv[v[i]];
        indexes[v[i]].push_back(i);
    }

    int q;
    cin >> q;
    for(int i = 0; i < q; ++i) {
        int start, sz;
        cin >> start >> sz;
        start--;
        set<int> query;
        for(int j = 0; j < sz; j++) {
            int t;
            cin >> t;
            if(s.count(t) == 0) continue;
            query.insert(conv[t]);
        }
        vector<int> actual;
        for(auto i : query) {
            actual.push_back(i);
        }
        solve(start, indexes, actual, n);
    }

}
