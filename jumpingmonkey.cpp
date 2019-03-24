#include <bits/stdc++.h>

using namespace std;

int find(vector<int>& d, int a) {
    if(d[a] < 0) return a;
    return d[a] = find(d,d[a]);
}

void join(vector<int>& d, int a, int b) {
    a = find(d,a);
    b = find(d,b);
    if(a == b) return;
    d[a] = b;
}

int n, m;

bool bfs(int state, vector<vector<int>>& adj) {
    queue<int> q;
    q.push(state);

    vector<bool> vis(1<<n,false);
    vector<pair<int,int>> par(1<<n);
    par[state] = {-1,-1};
    vis[state] = true;

    bool works = false;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        if(curr == 0) {
            works = true;
            break;
        }

        // For each node, if we shoot it,
        for(int i = 0; i < n; i++) {
            int next = 0;
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                if(curr & (1<<j)) {
                    for(auto k : adj[j]) {
                        next |= (1 << k);
                    }
                }
            }
            if(!vis[next]) {
                vis[next] = true;
                par[next] = {curr,i};
                q.push(next);
            }
        }

    }

    if(works) {
        vector<int> path;
        int curr = 0;
        while(curr != state) {
            path.push_back(par[curr].second);
            curr = par[curr].first;
        }
        cout << path.size() << ": ";
        for(int i = path.size()-1; i >= 0; i--) {
            cout << path[i] << " ";
        }
        cout << endl;
    }

    return works;
}

void solve() {
    vector<int> d(n,-1);
    vector<vector<int>> adj(n);

    bool works = true;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if(find(d,u) == find(d,v)) {
            works = false;
        }
        join(d,u,v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(!works) {
        cout << "Impossible" << endl;
        return;
    }

    if(!bfs((1<<n)-1,adj)) {
        cout << "Impossible" << endl;
    }
}

int main() {
    while(true) {
        cin >> n >> m;
        if(n == 0 && m == 0) {
            break;
        }
        solve();
    }
}


