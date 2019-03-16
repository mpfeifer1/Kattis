#include <bits/stdc++.h>

using namespace std;

int n, m;

int topo(vector<vector<int>> adj, vector<int> deg, vector<int> place, int start) {
    vector<queue<int>> q;
    q.resize(2);

    for(int i = 0; i < n; i++) {
        if(deg[i] == 0) {
            q[place[i]].push(i);
        }
    }

    int curr = start;
    int swaps = 0;
    while(!q[0].empty() || !q[1].empty()) {
        while(!q[curr].empty()) {
            int t = q[curr].front();
            q[curr].pop();

            for(auto i : adj[t]) {
                deg[i]--;
                if(deg[i] == 0) {
                    q[place[i]].push(i);
                }
            }
        }

        curr ^= 1;
        swaps++;
    }

    return swaps-1;
}

void solve() {
    cin >> n >> m;

    vector<int> place(n);
    for(auto& i : place) {
        cin >> i;
        i--;
    }

    vector<vector<int>> adj(n);
    vector<int> deg(n,0);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;

        adj[u].push_back(v);
        deg[v]++;
    }

    int swaps = min(topo(adj,deg,place,0),topo(adj,deg,place,1));
    cout << swaps << endl;
}

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        solve();
    }
}
