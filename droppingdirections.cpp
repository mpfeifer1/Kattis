#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool>& visNS, vector<bool>& visEW, int curr, int par) {
    bool NS;
    int next;
    for(int i = 0; i < 4; i++) {
        if(adj[curr][i] == par) {
            NS = (i == 0 || i == 1);
            next = (i ^ 1);
        }
    }

    if(NS) {
        if(visNS[curr]) return;
        visNS[curr] = true;
    }
    else {
        if(visEW[curr]) return;
        visEW[curr] = true;
    }

    dfs(adj, visNS, visEW, adj[curr][next], curr);
}

void solve() {
    int n, m;
    cin >> n >> m;
    m--;

    vector<vector<int>> adj(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 4; j++) {
            int t;
            cin >> t;
            t--;
            adj[i].push_back(t);
        }
        swap(adj[i][1], adj[i][2]);
    }

    vector<bool> visNS(n,false);
    vector<bool> visEW(n,false);

    dfs(adj, visNS, visEW, m, adj[m][0]);
    dfs(adj, visNS, visEW, m, adj[m][2]);

    int c = 0;
    for(int i = 0; i < n; i++) {
        if(!visNS[i]) {
            dfs(adj, visNS, visEW, i, adj[i][0]);
            c++;
        }
        if(!visEW[i]) {
            dfs(adj, visNS, visEW, i, adj[i][2]);
            c++;
        }
    }

    cout << c << endl;
}

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        solve();
    }
}
