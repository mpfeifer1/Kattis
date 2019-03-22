#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = (ll)1 << 60;

struct maxflow {

    struct edge {
        ll a, b, cap, flow;
    };

    ll n, s, t;
    vector<ll> d, ptr, q;
    vector<edge> e;
    vector<vector<ll>> g;

    maxflow(int _n, int _s, int _t) : n(_n), s(_s), t(_t) {
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

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    maxflow mf(n,0,1); // ARE SOURCE AND SINK RIGHT???

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        mf.addedge(u,v,w);
        mf.addedge(v,u,w);
    }

    vector<int> flows;
    flows.push_back(mf.getflow());

    for(int i = 0; i < k; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        mf.addedge(u,v,w);
        mf.addedge(v,u,w);
        flows.push_back(flows.back()+mf.getflow());
    }

    for(auto i : flows) {
        cout << i << endl;
    }
}
