#include <bits/stdc++.h>

using namespace std;

bool same(vector<int>& color) {
    vector<int> v(2,0);
    for(auto& i : color) {
        v[i]++;
    }
    return v[0] == 0 || v[1] == 0;
}

void flip(int toggle, vector<int>& color, vector<vector<int>>& adj) {
    vector<bool> vis(color.size(),false);

    queue<int> q;
    q.push(toggle);

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        if(vis[curr]) {
            continue;
        }
        vis[curr] = true;

        for(auto next : adj[curr]) {
            if(color[curr] == color[next]) {
                q.push(next);
            }
        }

        color[curr] ^= 1;
    }
}

int solve(int toggle, vector<int> color, vector<vector<int>>& adj) {
    int ct = 0;

    while(!same(color)) {
        ct++;
        flip(toggle, color, adj);
    }
    return ct;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> color(n);
    for(auto& i : color) {
        cin >> i;
    }
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        n1--; n2--;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    int best = n+1;
    for(int i = 0; i < n; i++) {
        best = min(best,solve(i, color, adj));
    }

    cout << best << endl;
}
