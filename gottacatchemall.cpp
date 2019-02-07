#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = (ll)1 << 60;

int main() {
    int n;
    cin >> n;

    set<pair<int,int>> seen;
    vector<pair<int,int>> edges;
    vector<vector<int>> adj(n);

    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;

        if(u > v) swap(u,v);
        if(seen.count({u,v})) continue;
        seen.insert({u,v});
        edges.push_back({u,v});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0; i < n; i++) {
        sort(adj[i].begin(),adj[i].end());
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += (ll)adj[i].size() * (adj[i].size()-1);
    }

    for(auto i : edges) {
        int u = i.first;
        int v = i.second;
        if(adj[u].size() > adj[v].size()) {
            swap(u,v);
        }
        int pos = 0;
        for(auto& j : adj[u]) {
            auto it = lower_bound(adj[v].begin()+pos,adj[v].end(),j);
            if(it != adj[v].end() && *it == j) {
                ans -= 2;
            }
            pos = it - adj[v].begin();
        }
    }

    cout << ans << endl;
}
