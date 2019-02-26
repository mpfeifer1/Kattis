#include <bits/stdc++.h>

using namespace std;

struct hashed {
    char f, l;
    vector<int> ct;
};

bool operator<(const hashed& h1, const hashed& h2) {
    return tie(h1.f,h1.l,h1.ct) <
           tie(h2.f,h2.l,h2.ct);
}

void solve(string s) {
    // Set up memory for hashing
    map<hashed,string> hashes;
    set<hashed> dup;
    vector<int> empty(26,0);

    // Read in input, build dictionary of hashes
    int d;
    cin >> d;
    bool ambig = false;
    for(int i = 0; i < d; i++) {
        vector<int> ct = empty;
        string s;
        cin >> s;
        for(auto j : s) {
            ct[j-'a']++;
        }

        hashed h = {s.front(),s.back(),ct};

        // If we have one of this word already, we need to make sure we treat it as multiple
        if(hashes.count(h) || dup.count(h)) {
            dup.insert(h);
        }

        // It's the first word with these counts, so we can use it
        else {
            hashes[h] = s;
        }
    }

    // Find the hash for each subsegment
    // For each start point
    vector<vector<hashed>> subhashes;
    subhashes.resize(s.size()+1,vector<hashed>(s.size()+1));
    for(int i = 0; i < s.size(); i++) {
        vector<int> ct = empty;
        // For each end point
        for(int j = i; j < s.size(); j++) {
            ct[s[j]-'a']++;
            subhashes[i][j] = {s[i],s[j],ct};
        }
    }

    // Count solutions
    // memo[ct_chars] = <num ways>;
    vector<int> memo;
    vector<pair<int,hashed>> par(s.size()+1,{-1,{'?','?',empty}});
    memo.resize(s.size()+1, 0);
    memo[0] = 1;

    // For each count of chars
    for(int i = 1; i <= s.size(); i++) {
        // For each count of chars for the first half
        for(int j = 0; j < i; j++) {
            // Here, we'll check if it's possible to go from j to i
            bool workshere = (memo[j] > 0) && hashes.count(subhashes[j][i-1]);
            if(workshere) {
                int mul = 1;
                if(dup.count(subhashes[j][i-1])) mul++;
                memo[i] += memo[j] * mul;
                par[i] = {j,subhashes[j][i-1]};
            }
        }
    }

    // If ambiguous, set ambiguous
    if(memo[s.size()] > 1) ambig = true;

    // If impossible, set that
    bool works = true;
    if(memo[s.size()] == 0) works = false;

    // Extract answer from DP
    vector<string> ans;
    int curr = s.size();
    while(par[curr].first != -1) {
        string here = hashes[par[curr].second];
        ans.push_back(here);
        curr = par[curr].first;
    }
    reverse(ans.begin(),ans.end());

    // Print answer
    if(!works) {
        cout << "impossible" << endl;
    }
    else if(ambig) {
        cout << "ambiguous" << endl;
    }
    else {
        for(auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main() {
    string s;
    while(cin >> s) {
        solve(s);
    }
}
