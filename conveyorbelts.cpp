#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MAXN = 300*300+2;
const ll INF = (ll)1000000000;

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
		while(ll pushed = dfs(s,INF)) {
			flow += pushed;
        }
	}
	return flow;
}

int main() {
    ll n, k, m;
    cin >> n >> k >> m;

    ::n = n*k + 2;

    s = ::n-1;
    t = ::n-2;

    // For each node
    for(ll i = 0; i < n; i++) {
        // If it's a start node
        if(i < k) {
            ll time = i*n;
            addedge(s,i+time,1);
        }

        // If it's an end node
        if(i == n-1) {
            // Connect it to the sink for each time
            for(ll j = 0; j < k; j++) {
                ll time = j*n;
                addedge(i+time,t,INF);
            }
        }
    }

    // For each edge
    for(ll i = 0; i < m; i++) {
        // Read in edge
        ll n1, n2;
        cin >> n1 >> n2;
        n1--; n2--;


        // Build the edge for each timestamp
        for(ll j = 0; j < k; j++) {
            ll t1 = j*n;
            ll t2 = ((j+1)%k)*n;
            addedge(n1+t1,n2+t2,1);
        }
    }

    // Calculate max flow from s to t
    // Dinic's runs in E * V^2
    cout << dinic() << endl;
}
