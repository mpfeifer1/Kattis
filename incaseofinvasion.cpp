#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = (ll)1 << 60;
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





struct ed {
    ll u, v, w;
};

// dist[node][shelter] = val
vector<vector<ll>> dist;

bool works(ll time, ll n, ll m, ll s, vector<ll>& people, vector<pair<ll,ll>>& shelters, vector<ed>& edges) {
    ::n = 2 + s + (1 << s);
    ::s = ::n - 1;
    ::t = ::n - 2;

    // shelters are 0->s-1
    // nodes are (your bits) + s

    // Build composite nodes
    ll total = 0;
    vector<ll> caps((1<<s),0);
    for(ll i = 0; i < n; i++) {
        ll mask = 0;
        for(ll j = 0; j < s; j++) {
            if(dist[i][j] <= time) {
                mask |= (1 << j);
            }
        }
        caps[mask] += people[i];
        total += people[i];
    }

    // Add edge from the source to each shelter
    for(ll i = 0; i < s; i++) {
        addedge(::s,i,shelters[i].second);
    }

    // Add edge from each node to the sink
    // Add edge from each shelter to each node (if it can be reached)
    for(ll i = 0; i < (1<<s); i++) {
        addedge(s+i,::t,caps[i]);

        for(ll j = 0; j < s; j++) {
            if(i & (1<<j)) {
                addedge(j,s+i,inf);
            }
        }
    }

    ll flow = getflow();
    ////cout << "Tot" << total << endl;
    //cout << time << ": " << flow << endl;
    reset();
    return total == flow;
}

void dijkstra(ll s, vector<pair<ll,ll>>& shelters, vector<vector<pair<ll,ll>>>& adj) {
    dist.resize(adj.size(),vector<ll>(s,inf));
    for(ll i = 0; i < s; i++) {
        set<pair<ll,ll>> q;
        q.insert({0,shelters[i].first});
        dist[shelters[i].first][i] = 0;

        while(!q.empty()) {
            ll curr = q.begin()->second;
            q.erase(q.begin());
            for(auto j : adj[curr]) {
                ll next = j.first;
                ll weight = j.second;

                if(dist[next][i] > dist[curr][i] + weight) {
                    q.erase({dist[next][i],next});
                    dist[next][i] = dist[curr][i] + weight;
                    q.insert({dist[next][i],next});
                }
            }
        }
    }
}

int main() {
    ll n, m, s;
    vector<ll> people;
    vector<pair<ll,ll>> shelters;
    vector<ed> edges;
    vector<vector<pair<ll,ll>>> adj;

    cin >> n >> m >> s;

    people.resize(n);
    for(auto& i : people) {
        cin >> i;
    }

    adj.resize(n);
    for(ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        edges.push_back({u,v,w});
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    shelters.resize(s);
    for(auto& i : shelters) {
        cin >> i.first >> i.second;
        i.first--;
    }

    dijkstra(s, shelters, adj);

    ll lo = -1;
    ll hi = inf;

    while(lo + 1 < hi) {
        ll mi = (hi + lo) / 2;
        if(works(mi,n,m,s,people,shelters,edges)) {
            hi = mi;
        }
        else {
            lo = mi;
        }
    }

    cout << hi << endl;
}
