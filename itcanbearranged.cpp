#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll inf = (ll)1 << 60;
const ll MAXN = 100000 + 10;

struct edge {
    ll a, b, cap, flow;
};

ll n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<ll> g[MAXN];

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
    memset(d, -1, n * sizeof d[0]);
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
        memset(ptr, 0, n * sizeof ptr[0]);
        while(ll pushed = dfs(s,inf)) {
            flow += pushed;
        }
    }
    return flow;
}

// This requres 'n' to be set to
// its value from the previous run
// This removes all edges from the graph
void reset() {
    e.clear();
    for(ll i = 0; i < n; i++) {
        g[i].clear();
    }
}

struct course {
    ll a, b, s;
};

ll ceildiv(ll top, ll bot) {
    return (top + bot - 1) / bot;
}

bool works(vector<course>& v, vector<vector<ll>>& clean, ll conflicts, ll n, ll sum, ll size) {
    reset();

    ::n = 4 + (2 * n);
    ::s = ::n-1;
    ::t = ::n-2;
    ll ss = ::n-3;
    ll tt = ::n-4;

    for(ll i = 0; i < n; i++) {
        ll cap = ceildiv(v[i].s, size);
        addedge(s,i,cap);
        addedge(i,ss,inf);

        addedge(tt,i+n,inf);
        addedge(i+n,t,cap);
    }

    addedge(ss,tt,conflicts);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(v[i].b + clean[i][j] < v[j].a) {
                addedge(i,j+n,inf);
            }
        }
    }

    return getflow() >= sum;
}

void solve() {
    ll n, m;
    cin >> n >> m;

    ll sum = 0;

    vector<course> v(n);
    for(auto& c : v) {
        cin >> c.a >> c.b >> c.s;
        sum += ceildiv(c.s,m);
    }

    vector<vector<ll>> clean;
    clean.resize(n, vector<ll>(n));
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            cin >> clean[i][j];
        }
    }

    ll lo = 1;
    ll hi = sum;
    ll ans = sum;
    while(hi - lo > 1) {
        ll mi = (hi + lo) / 2;
        if(works(v,clean,mi,n,sum,m)) {
            hi = mi;
            ans = mi;
        }
        else {
            lo = mi;
        }
    }

    cout << ans << endl;
}

int main() {
    ll cases;
    cin >> cases;
    for(ll i = 1; i <= cases; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
}
