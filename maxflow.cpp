#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = (ll) 1 << 63 - 1;

const int size = 500;

struct edge {
    ll u, v, w;
};

ll bfs(vector<vector<ll>>& og, vector<vector<ll>>& rg, vector<ll>& par, ll s, ll t, ll n) {
    vector<ll> f(size, 0);

    vector<bool> visited(size, false);
    visited[s] = true;

    queue<ll> q;
    q.push(s);
    par[s] = -1;
    f[s] = inf;

    while(!q.empty()) {
        ll u = q.front();
        q.pop();
        for(ll v = 0; v < n; v++) {
            if(visited[v] == false && rg[u][v] > 0) {
                q.push(v);
                par[v] = u;
                visited[v] = true;
                f[v] = min(f[u], rg[u][v]);
            }
        }
    }

    if(visited[t]) {
        return f[t];
    }
    return 0;
}

void fulkerson(vector<vector<ll>>& og, vector<vector<ll>>& rg, ll s, ll t, ll n) {
    ll max_flow = 0, path_flow = 0;

    vector<ll> par(size);

    while(path_flow = bfs(og, rg, par, s, t, n)) {
        for(ll v = t; v != s; v = par[v]) {
            ll u = par[v];
            rg[u][v] -= path_flow;
            rg[v][u] += path_flow;
        }
        max_flow += path_flow;
    }

    vector<edge> used;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            if(og[i][j] > 0 && rg[i][j] < og[i][j]) {
                edge e;
                e.u = i;
                e.v = j;
                e.w = og[i][j] - rg[i][j];
                used.push_back(e);
            }
        }
    }

    cout << n << " " << max_flow << " " << used.size() << endl;
    for(ll i = 0; i < used.size(); i++) {
        cout << used[i].u << " " << used[i].v << " " << used[i].w << endl;
    }
}

int main() {
    ll n, m, s, t;
    cin >> n >> m >> s >> t;

    // Set up original graph and residual graph
    vector<vector<ll>> og, rg;
    og.resize(size, vector<ll>(size, 0));
    rg.resize(size, vector<ll>(size, 0));

    for(ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;

        og[u][v] = w;
        rg[u][v] = w;
    }

    fulkerson(og, rg, s, t, n);
}
