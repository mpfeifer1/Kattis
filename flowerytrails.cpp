#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = ((ll)1 << 63) - 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    vector<ll> dist(n, inf);
    vector<vector<pair<ll,ll>>> parent(n);
    vector<vector<pair<ll,ll>>> adj(n);
    vector<bool> vis(n, false);

    unordered_map<ll, unordered_map<ll, ll>> mat;

    for(ll i = 0; i < m; i++) {
        ll n1, n2, w;
        cin >> n1 >> n2 >> w;

        if(n1 == n2) {
            continue;
        }

        adj[n1].push_back({w, n2});
        adj[n2].push_back({w, n1});

        if(mat.count(n1) == 0 || mat[n1].count(n2) == 0) {
            mat[n1][n2] = w;
            mat[n2][n1] = w;
        }

        mat[n1][n2] = min(mat[n1][n2], w);
        mat[n2][n1] = min(mat[n2][n1], w);
    }

    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0,0});
    dist[0] = 0;

    while(!pq.empty()) {
        ll curr = pq.top().second;
        pq.pop();

        if(vis[curr]) {
            continue;
        }
        vis[curr] = true;

        for(auto i : adj[curr]) {
            ll weight = i.first;
            ll next = i.second;

            if(dist[curr] + weight < dist[next]) {
                dist[next] = dist[curr] + weight;
                parent[next].clear();
                parent[next].push_back({dist[curr] + weight, curr});
                pq.push({dist[curr] + weight, next});
            }
            else if(dist[curr] + weight == dist[next]) {
                parent[next].push_back({dist[curr] + weight, curr});
            }
        }
    }

    vis.clear();
    vis.resize(n, false);

    queue<int> q;
    q.push(n-1);

    ll total = 0;
    while(!q.empty()) {
        ll curr = q.front();
        q.pop();

        if(vis[curr]) {
            continue;
        }
        vis[curr] = true;

        for(auto i : parent[curr]) {
            total += mat[curr][i.second];
            q.push(i.second);
        }
    }

    cout << total * 2 << endl;
}
