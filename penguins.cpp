#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
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

struct ice {
    ld x, y;
    ll peng, jump;
};

ld dist(pair<ld,ld>& p1, pair<ld,ld>& p2) {
    ld d1 = pow(p1.first - p2.first,2);
    ld d2 = pow(p1.second - p2.second,2);
    return sqrt(d1+d2);
}

vector<ice> ices;

bool solve(ll n, ld d, ll end) {
    reset();

    ::n = 2 * n + 2;
    ::s = ::n - 1;
    ::t = ::n - 2;

    // Count all penguins
    ll total = 0;
    for(auto i : ices) {
        total += i.peng;
    }

    // Vin: [0,n-1]
    // Vout: [n,2n-1]

    // Add edge from end node to sink
    addedge(end,::t,total);

    // Add edge from source to each iceberg
    for(ll i = 0; i < n; i++) {
        addedge(::s,i,ices[i].peng);
    }

    // Add edge from each node to itself
    for(ll i = 0; i < n; i++) {
        addedge(i,n+i,ices[i].jump);
    }

    // Add internal edges
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            pair<ld,ld> p1 = {ices[i].x,ices[i].y};
            pair<ld,ld> p2 = {ices[j].x,ices[j].y};
            if(dist(p1,p2) <= d) {
                addedge(i+n,j,inf);
            }
        }
    }

    // If flow = total, it's possible
    return getflow() == total;
}

int main() {
    ll n; ld d;
    cin >> n >> d;
    ices.resize(n);
    for(auto& i : ices) {
        cin >> i.x >> i.y >> i.peng >> i.jump;
    }

    vector<ll> ans;
    for(ll i = 0; i < n; i++) {
        if(solve(n,d,i)) {
            ans.push_back(i);
        }
    }

    if(ans.size() == 0) {
        cout << -1 << endl;
    }
    else {
        for(auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}
