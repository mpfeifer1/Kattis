#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = (ll)1 << 60;

int main() {
    ll n, m;
    cin >> n >> m;

    // {dest,weight}
    vector<vector<pair<ll,ll>>> adj(n);

    for(ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--; v--;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    // hasball[node][balli] = true if the ith dragonball is on this node
    vector<vector<bool>> hasball(n,vector<bool>(7,false));
    for(ll i = 0; i < 7; i++) {
        ll t;
        cin >> t; t--;

        hasball[t][i] = true;
    }

    // Find starting node & set
    int startset = 0;
    for(int i = 0; i < 7; i++) {
        if(hasball[0][i]) startset |= 1 << i;
    }

    // Prepare dijkstra's
    vector<vector<ll>> dist(n, vector<ll>(1<<7,inf));
    dist[0][startset] = 0;

    // {-weight,{destnode,destsubset}}
    priority_queue<pair<ll,pair<ll,ll>>> q;
    q.push({0,{0,startset}});

    // Run dijkstra's
    while(!q.empty()) {
        ll currn = q.top().second.first;
        ll currset = q.top().second.second;
        q.pop();

        for(auto i : adj[currn]) {
            ll nextn = i.first;
            ll weight = dist[currn][currset] + i.second;

            ll nextset = currset;
            for(ll j = 0; j < 7; j++) {
                if(hasball[nextn][j]) {
                    nextset |= 1 << j;
                }
            }

            if(dist[nextn][nextset] > weight) {
                dist[nextn][nextset] = weight;
                q.push({-weight, {nextn,nextset}});
            }

        }
    }

    // Find and print answer
    ll best = inf;
    for(ll i = 0; i < n; i++) {
        best = min(best,dist[i][(1<<7)-1]);
    }
    cout << best << endl;
}
