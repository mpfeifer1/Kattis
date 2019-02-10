#include <bits/stdc++.h>

using namespace std;

vector<int> leaves;
vector<bool> vis;
vector<vector<int>> adj;

void dfs(int curr) {
    vis[curr] = true;

    bool leaf = true;
    for(auto next : adj[curr]) {
        if(!vis[next]) {
            leaf = false;
            dfs(next);
        }
    }

    if(leaf) {
        leaves.push_back(curr);
    }
}

int main() {
    int n, r;
    cin >> n >> r;

    adj.resize(n);
    for(int i = 0; i < n-1; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    vis.resize(n,false);
    dfs(r);
    if(adj[r].size() == 1) {
        leaves.push_back(r);
    }

    int tot = leaves.size();
    int ans = (tot+1) / 2;
    int add = tot / 2;

    cout << ans << endl;
    for(int i = 0; i < ans; i++) {
        cout << leaves[i] << " " << leaves[(i+add)%tot] << endl;
    }
}
