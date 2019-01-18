#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll inf = (ll)1 << 60;
const ll MAXN = 1000000 + 10;

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
    for(int i = 0; i < n; i++) {
        g[i].clear();
    }
}

struct road {
    ll a, b, cap, t;
};

void solve() {
    ll locations, start, group, time;
    cin >> locations >> start >> group >> time;
    start--;
    time++;

    ll ends;
    cin >> ends;
    vector<ll> loc(ends);
    for(auto& i : loc) {
        cin >> i;
        i--;
    }

    ll r;
    cin >> r;
    vector<road> roads(r);
    for(auto& i : roads) {
        cin >> i.a >> i.b >> i.cap >> i.t;
        i.a--;
        i.b--;
    }

    ::n = locations * time + 2;
    ::s = ::n-1;
    ::t = ::n-2;

    // Add edge from source to first location
    addedge(::s,start,group);

    // Add edges from nodes to themselves so you can wait
    for(int i = 1; i < time; i++) {
        ll t1 = (i-1) * locations;
        ll t2 = i * locations;
        for(int j = 0; j < locations; j++) {
            addedge(t1+j,t2+j,inf);
        }
    }

    // Add each road at each timestep
    for(auto& i : roads) {
        for(ll j = 0; j < time; j++) {
            if(j + i.t >= time) break;
            ll t1 = j;
            ll t2 = j + i.t;
            ll n1 = t1*locations + i.a;
            ll n2 = t2*locations + i.b;
            addedge(n1,n2,i.cap);
        }
    }

    // Add edge from each facility at each time to the sink
    for(auto i : loc) {
        for(ll j = 0; j < time; j++) {
            ll n1 = j * locations + i;
            addedge(n1, ::t, inf);
        }
    }

    // Run flow
    cout << getflow() << endl;

    reset();
}

int main() {
    ll cases;
    cin >> cases;
    while(cases--) {
        solve();
    }
}
