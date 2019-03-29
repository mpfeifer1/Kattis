#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll big = 1000001 * 100;
ll inf = (ll)1 << 60;

struct mincostmaxflow {
    struct edge {
        ll a, b, cap, cost, flow;
        size_t back;
    };

    vector<edge> e;
    vector<vector<ll>> g;
    ll n, s, t;
    ll k = inf; // The maximum amount of flow allowed

    mincostmaxflow(ll _n, ll _s, ll _t) : n(_n), s(_s), t(_t) {
        g.resize(n);
    }

    void addedge(ll a, ll b, ll cap, ll cost) {
        edge e1 = {a,b,cap,cost,0,g[b].size()};
        edge e2 = {b,a,0,-cost,0,g[a].size()};
        g[a].push_back((ll) e.size());
        e.push_back(e1);
        g[b].push_back((ll) e.size());
        e.push_back(e2);
    }

    // Returns {flow,cost}
    pair<ll,ll> getflow() {
        ll flow = 0, cost = 0;
        while(flow < k) {
            vector<ll> id(n, 0);
            vector<ll> d(n, inf);
            vector<ll> q(n);
            vector<ll> p(n);
            vector<size_t> p_edge(n);
            ll qh=0, qt=0;
            q[qt++] = s;
            d[s] = 0;
            while(qh != qt) {
                ll v = q[qh++];
                id[v] = 2;
                if(qh == n) qh = 0;
                for(size_t i=0; i<g[v].size(); ++i) {
                    edge& r = e[g[v][i]];
                    if(r.flow < r.cap && d[v] + r.cost < d[r.b]) {
                        d[r.b] = d[v] + r.cost;
                        if(id[r.b] == 0) {
                            q[qt++] = r.b;
                            if(qt == n) qt = 0;
                        }
                        else if(id[r.b] == 2) {
                            if(--qh == -1) qh = n-1;
                            q[qh] = r.b;
                        }
                        id[r.b] = 1;
                        p[r.b] = v;
                        p_edge[r.b] = i;
                    }
                }
            }
            if(d[t] == inf) break;
            ll addflow = k - flow;
            for(ll v=t; v!=s; v=p[v]) {
                ll pv = p[v]; size_t pr = p_edge[v];
                addflow = min(addflow, e[g[pv][pr]].cap - e[g[pv][pr]].flow);
            }
            for(ll v=t; v!=s; v=p[v]) {
                ll pv = p[v]; size_t pr = p_edge[v], r = e[g[pv][pr]].back;
                e[g[pv][pr]].flow += addflow;
                e[g[v][r]].flow -= addflow;
                cost += e[g[pv][pr]].cost * addflow;
            }
            flow += addflow;
        }
        return {flow,cost};
    }
};

int main() {
    ll n, m;
    cin >> n >> m;

    ll nodes = ((n+10)*2)+2;
    ll s = nodes-1;
    ll t = nodes-2;
    mincostmaxflow mf(nodes,s,t);

    // Create the initial two edges
    mf.addedge(s,0,m,0); // Source to 0's in
    for(int i = 1; i <= n; i++) {
        mf.addedge((i*2)+1,t,1,0); // n's out to sink
    }

    // Build internal edges
    for(ll i = 0; i < n; i++) {
        for(ll j = i; j < n; j++) {
            ll t;
            cin >> t;
            mf.addedge((2*i)+1,(2*(j+1)),1,t);
        }
    }

    mf.addedge(0,1,m,0);

    // Connect node in/out
    for(ll i = 1; i < n+1; i++) {
        mf.addedge(2*i,2*i+1,1,-big);
    }

    // Connect the source to the sink so we can skip extra paths
    mf.addedge(0,t,inf,0);

    pair<ll,ll> res = mf.getflow();
    res.second += big * n;

    cout << res.second << endl;
}
