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
        ans += adj[i].size() * (adj[i].size()-1);
    }

    cout << ans << " ";

    for(auto i : edges) {
        if(adj[i.first].size() > adj[i.second].size()) {
            swap(i.first,i.second);
        }
        int pos = 0;
        for(auto j : adj[i.first]) {
            auto it = lower_bound(adj[i.second].begin()+pos,adj[i.second].end(),j);
            if(*it == j) {
                ans -= 2;
            }
            else {
                cout << "fuck " << *it << endl;
            }
            pos = it - adj[i.second].begin();
        }
    }

    cout << ans << endl;
}
