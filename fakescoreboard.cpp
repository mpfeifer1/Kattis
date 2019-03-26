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

// [0,n) teams
// [n,n+m) problems
// [n+m, n+m+2) source/sink

int total;
int n, m;

void solve() {
    // Read in the teams and problems
    vector<int> v1;
    vector<int> v2;
    v1.resize(n);
    v2.resize(m);

    for(auto& i : v1) cin >> i;
    for(auto& j : v2) cin >> j;

    int s1 = 0;
    int s2 = 0;
    for(auto i : v1) s1 += i;
    for(auto i : v2) s2 += i;

    // If the totals don't line up, it's impossible
    if(s1 != s2) {
        cout << "Impossible" << endl;
        cout << endl;
        return;
    }
    total = s1;

    // Initialize the flow graph
    int sz = n+m+2;
    int s = sz-1;
    int t = sz-2;
    maxflow mf(sz,s,t);

    // Add internal edges
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            mf.addedge(i,n+j,1);
        }
    }

    // Add edges from source to teams
    for(int i = 0; i < n; i++) {
        mf.addedge(s,i,v1[i]);
    }

    // Add edges from problems to sink
    for(int j = 0; j < m; j++) {
        mf.addedge(n+j,t,v2[j]);
    }

    int flow = mf.getflow();

    if(flow != total) {
        cout << "Impossible" << endl;
        cout << endl;
        return;
    }

    string ans;
    
    // For each internal edge (by importance highest to lowest)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            
            // If it wasn't used, we don't need it, remove it
            int oldflow = mf.e[(i*m+j)*2].flow;
            if(oldflow == 0) {
                ans.push_back('N');
                mf.e[(i*m+j)*2].cap = 0;
            }

            // If it was used, try removing it
            else {
                mf.e[(i*m+j)*2].flow--;
                mf.e[(i*m+j)*2].cap--;

                mf.e[(n*m)*2 + (i*2)].flow--;
                mf.e[(n*m)*2 + (n*2) + (j*2)].flow--;

                // If it wasn't needed, leave it out
                int flow =  mf.getflow();
                if(flow == 1) {
                    ans.push_back('N');
                }

                // If it was needed, reinsert it and continue on
                else {
                    ans.push_back('Y');

                    mf.e[(i*m+j)*2].flow++;
                    mf.e[(i*m+j)*2].cap++;

                    mf.e[(n*m)*2 + (i*2)].flow++;
                    mf.e[(n*m)*2 + (n*2) + (j*2)].flow++;
                }
            }
        }
    }
    
    // Print the answer
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << ans[i*m+j];
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    while(true) {
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        solve();
    }
}


