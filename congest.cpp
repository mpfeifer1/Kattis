#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = (ll)1 << 60;

const ll MAXN = 25000 + 2;

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
	if(!flow)  return 0;
	if(v == t)  return flow;
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

ll dinic() {
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
    for(ll i = 0; i < MAXN; i++) {
        d[i] = 0;
        ptr[i] = 0;
        q[i] = 0;
        g[i].clear();
    }
}

ll calc(map<pair<ll,ll>,ll> edges, vector<tuple<ll,ll,ll>>& extras) {
    reset();
    for(auto& i : edges) {
        pair<ll,ll> p = i.first;
        ll cap = i.second;
        addedge(p.first, p.second, cap);
    }

    for(auto& i : extras) {
        ll u = get<0>(i);
        ll v = get<1>(i);
        ll cap = get<2>(i);
        addedge(u,v,cap);
    }

    return dinic();
}

bool cmp(pair<ll,ll>& e1, pair<ll,ll>& e2) {
    return e1.second < e2.second;
}

int main() {
    ll m, c;
    cin >> n >> m >> c;

    // Set n, source, sink
    n += 2;
    s = n-1;
    t = n-2;

    vector<tuple<ll,ll,ll>> input;

    // Set up the graph for dijkstra's
    vector<vector<pair<ll,ll>>> adj(n);
    for(ll i = 0; i < m; i++) {
        ll n1, n2, w;
        cin >> n1 >> n2 >> w;
        n1--; n2--;

        adj[n1].push_back({n2,w});
        adj[n2].push_back({n1,w});

        input.push_back({n1,n2,w});
        input.push_back({n2,n1,w});
    }

    // Sort adj lists so the best path is found first
    // unnecessary???
    for(auto& i : adj) {
        sort(i.begin(), i.end(), cmp);
    }

    // Prepare dijkstra's
    vector<ll> dist(n,inf);
    vector<bool> vis(n,false);
    priority_queue<pair<ll,ll>> q;
    q.push({0,0});
    dist[0] = 0;

    // Run dijkstra's
    while(!q.empty()) {
        ll curr = q.top().second;
        q.pop();

        if(vis[curr]) continue;
        vis[curr] = true;

        for(auto& j : adj[curr]) {
            ll next = j.first;
            ll weight = j.second;

            if(dist[next] > dist[curr] + weight) {
                dist[next] = dist[curr] + weight;
                q.push({-dist[next],next});
            }
        }
    }

    // Store the edges
    map<pair<ll,ll>,ll> edges;

    // Grab all the 'keep' edges, count them
    for(auto i : input) {
        ll u = get<0>(i);
        ll v = get<1>(i);
        ll w = get<2>(i);

        if(dist[u] + w == dist[v]) {
            edges[{v,u}]++;
        }
    }

    // Map each time to its additional edges
    map<ll,vector<tuple<ll,ll,ll>>> times;

    // Add edges form the source to anywhere with cars
    vector<ll> count(n,0);
    for(ll i = 0; i < c; i++) {
        ll t; cin >> t;
        t--;
        count[t]++;
    }
    for(ll i = 0; i < n; i++) {
        if(count[i] > 0) {
            times[dist[i]].push_back({s,i,count[i]});
        }
    }

    // Add an edge from the last node to the sink
    edges[{0,t}] = inf;

    // Run all the max flows necessary
    ll ans = 0;
    for(auto i : times) {
        ans += calc(edges, i.second);
    }

    cout << ans << endl;
}
