#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> buildtree(string s) {
    int n = s.size()/2 + 1;
    vector<vector<int>> adj(n);
    vector<int> par(n,-1);

    int curr = 0;
    int total = 0;

    for(auto i : s) {
        if(i == '1') {
            curr = par[curr];
        }
        if(i == '0') {
            total++;
            adj[curr].push_back(total);
            par[total] = curr;
            curr = total;
        }
    }

    return adj;
}

pair<int,string> buildstring(vector<vector<int>>& adj, int curr) {
    if(adj[curr].size() == 0) {
        return {1, "1 "};
    }

    vector<string> all;
    int count = 0;
    for(auto next : adj[curr]) {
        pair<int,string> p = buildstring(adj, next);
        count += p.first;
        all.push_back(p.second);
    }

    sort(all.begin(), all.end());
    string ans = to_string(count) + " ";
    for(auto i : all) {
        ans += i;
    }

    return {count,ans};
}

void solve() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    vector<vector<int>> adj1 = buildtree(s1);
    vector<vector<int>> adj2 = buildtree(s2);

    string k1 = buildstring(adj1, 0).second;
    string k2 = buildstring(adj2, 0).second;

    if(k1 == k2) {
        cout << "same" << endl;
    }
    else {
        cout << "different" << endl;
    }
}

int main() {
    int cases;
    cin >> cases;
    cin.ignore();

    while(cases--) {
        solve();
    }
}
