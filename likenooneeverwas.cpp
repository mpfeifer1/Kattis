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

bool isprime(ll n) {
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    for(ll i = 3; i*i <= n; i+=2) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // Source, sink, the cakes, and hopefully enough for all prime factors
    ::n = 2 + 10000 + 5000;

    // Source is 0 so we can 1-index nodes
    ::s = 0;
    // Sink is n-1 so it's out of the way
    ::t = ::n-1;

    // Read in the input
    ll n;
    cin >> n;
    ll total = 0;
    vector<ll> val(n+1);
    vector<ll> cost(n+1);
    for(ll i = 1; i <= n; i++) {
        cin >> val[i];
        total += val[i];
    }
    for(ll i = 1; i <= n; i++) {
        cin >> cost[i];
    }

    // Connect each cake to the sink
    for(ll i = 1; i <= n; i++) {
        addedge(i,t,val[i]);
    }

    // Connect the source to all prime divisors
    ll node_id = n+1;
    vector<vector<ll>> ids(n+1);
    for(ll i = 2; i <= n; i++) {
        if(!isprime(i)) {
            continue;
        }
        ll prevcost = 0;
        ll ct = 0;
        ll t = n;
        while(t > 0) {
            ct++;
            ll currcost = ct * ct * cost[i];
            addedge(s,node_id,currcost-prevcost);
            prevcost = currcost;
            ids[i].push_back(node_id);
            node_id++;
            t /= i;
        }
    }

    // Connect all numbers to their prime divisors
    vector<ll> rem(n+1);
    for(ll i = 0; i <= n; i++) {
        rem[i] = i;
    }
    for(ll i = 2; i <= n; i++) {
        if(!isprime(i)) {
            continue;
        }
        for(ll j = i; j <= n; j += i) {
            ll ct = 0;
            while(rem[j] % i == 0) {
                // get the id for the nth of this factor
                ll node = ids[i][ct];
                addedge(node,j,inf);
                rem[j] /= i;
                ct++;
            }
        }
    }

    // Calculate max flow from s to t
    ll flow = getflow();
    cout << total - flow << endl;

    reset();
}
