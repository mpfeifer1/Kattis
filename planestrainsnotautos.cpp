#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll inf = (ll)1 << 60;

struct maxflow {
    struct edge {
        ll a, b, cap, flow;
    };

    ll n, s, t;
    vector<ll> d, ptr, q;
    vector<edge> e;
    vector<vector<ll>> g;

    maxflow(ll _n, ll _s, ll _t) : n(_n), s(_s), t(_t) {
        d.resize(n);
        ptr.resize(n);
        q.resize(n);
        g.resize(n);
    }

    void addedge(ll a, ll b, ll cap) {
        edge e1 = { a, b, cap, 0 };
        edge e2 = { b, a, 0, 0 };
        g[a].push_back((ll) e.size());
        e.push_back(e1);
        g[b].push_back((ll) e.size());
        e.push_back(e2);
    }

    bool bfs() {
        ll qh=0, qt=0;
        q[qt++] = s;
        d.assign(d.size(), -1);
        d[s] = 0;
        while(qh < qt && d[t] == -1) {
            ll v = q[qh++];
            for(size_t i=0; i<g[v].size(); ++i) {
                ll id = g[v][i],
                to = e[id].b;
                if(d[to] == -1 && e[id].flow < e[id].cap) {
                    q[qt++] = to;
                    d[to] = d[v] + 1;
                }
            }
        }
        return d[t] != -1;
    }

    ll dfs(ll v, ll flow) {
        if(!flow) return 0;
        if(v == t) return flow;
        for(; ptr[v]<(ll)g[v].size(); ++ptr[v]) {
            ll id = g[v][ptr[v]];
            ll to = e[id].b;
            if(d[to] != d[v] + 1)  continue;
            ll pushed = dfs(to, min (flow, e[id].cap - e[id].flow));
            if(pushed) {
                e[id].flow += pushed;
                e[id^1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

    ll getflow() {
        ll flow = 0;
        for(;;) {
            if(!bfs())  break;
            ptr.assign(ptr.size(), 0);
            while(ll pushed = dfs(s,inf)) {
                flow += pushed;
            }
        }
        return flow;
    }

};

void bfs(vector<vector<pair<ll,bool>>>& adj, vector<bool>& vis, ll start, bool forward) {
    queue<ll> q;
    q.push(start);
    while(!q.empty()) {
        ll curr = q.front();
        q.pop();
        if(vis[curr]) continue;
        vis[curr] = true;
        for(auto i : adj[curr]) {
            int next = i.first;
            if(i.second == forward) {
                q.push(next);
            }
        }
    }
}

int main() {
    // Start graph
    ll n, m;
    cin >> n >> m;
    ll sz = (n*2) + 2;
    maxflow mf(sz,sz-1,sz-2);

    // Connect source and sink
    for(ll i = 0; i < n; i++) {
        mf.addedge(mf.s,i,1);
        mf.addedge(n+i,mf.t,1);
    }

    // Connect internal nodes
    for(ll i = 0; i < m; i++) {
        ll n1, n2;
        cin >> n1 >> n2;
        n1--; n2--;
        mf.addedge(n1,n+n2,1);
    }

    // Get answer, if no flights, quit
    ll ans = (n-1) - mf.getflow();
    if(ans <= 0) {
        cout << 0 << endl;
        return 0;
    }

    // Normalize flow values
    for(int i = 0; i < mf.e.size(); i++) {
        if(i % 2 == 1) {
            mf.e[i].flow++;
        }
    }

    // Build the new adj list
    vector<vector<pair<ll,bool>>> adj(mf.n);
    for(auto i : mf.e) {
        adj[i.a].push_back({i.b,i.flow>0});
        adj[i.b].push_back({i.a,i.flow<=0});
    }

    // Run BFS from source and sink
    vector<bool> vis1(mf.n,false);
    vector<bool> vis2(mf.n,false);
    bfs(adj, vis1, mf.t, true);
    bfs(adj, vis2, mf.s, false);

    // Find who to print
    vector<bool> print(n,false);
    for(ll i = 0; i < 2 * n; i++) {
        if(i < n && vis2[i]) print[i] = true;
        if(i >= n && vis1[i]) print[i-n] = true;
    }

    // Print them
    cout << ans << endl;
    for(ll i = 0; i < n; i++) {
        if(print[i]) {
            cout << i+1 << " ";
        }
    }
    cout << endl;
}
