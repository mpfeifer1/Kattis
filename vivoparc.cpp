#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> type;


void solve(int pos) {
    int n = type.size();
    if(pos == type.size()) {
        for(int i = 0; i < n; ++i) {
            cout << i+1 << ' ' << type[i] << '\n';
        }
        exit(0);
    }
    for(int color = 1; color <= 4; ++color) {
        bool good = true;
        for(const int &to : adj[pos]) {
            if(to >= pos) break;
            if(type[to] == color) {
                good = false;
                break;
            }
        }
        if(good) {
            type[pos] = color;
            solve(pos+1);
        }
    }
}

int main() {
    int n;
    cin >> n;
    adj.resize(n);
    type.resize(n);
    int u, v;
    char dash;
    while(cin >> u >> dash >> v) {
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i < n; ++i) {
        sort(adj[i].begin(), adj[i].end());
        adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
    }
    solve(0);
}
