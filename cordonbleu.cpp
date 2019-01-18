#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll inf = (ll)1 << 60;

struct edge {
	ll b, u, c, f;
	size_t back;
};

void addedge(vector<vector<edge>>& g, ll a, ll b, ll u, ll c) {
	edge r1 = {b,u,c,0,g[b].size()};
	edge r2 = {a,0,-c,0,g[a].size()};
	g[a].push_back(r1);
	g[b].push_back(r2);
}

ll n, m, k = inf;

pair<ll,ll> mincostflow(vector<vector<edge>>& g, ll s, ll t) {
	ll flow = 0,  cost = 0;
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
			if(qh == n)  qh = 0;
			for(size_t i=0; i<g[v].size(); ++i) {
				edge& r = g[v][i];
				if(r.f < r.u && d[v] + r.c < d[r.b]) {
					d[r.b] = d[v] + r.c;
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
			addflow = min(addflow, g[pv][pr].u - g[pv][pr].f);
		}
		for(ll v=t; v!=s; v=p[v]) {
			ll pv = p[v]; size_t pr = p_edge[v], r = g[pv][pr].back;
			g[pv][pr].f += addflow;
			g[v][r].f -= addflow;
			cost += g[pv][pr].c * addflow;
		}
		flow += addflow;
	}
    return {flow,cost};
}

ll dist(pair<ll,ll>& p1, pair<ll,ll>& p2) {
    return abs(p1.first-p2.first) +
           abs(p1.second-p2.second);
}

int main(){
    ll n, m;
    cin >> n >> m;

    vector<pair<ll,ll>> bottles(n);
    vector<pair<ll,ll>> couriers(m);
    for(auto& i : bottles) {
        cin >> i.first >> i.second;
    }
    for(auto& i : couriers) {
        cin >> i.first >> i.second;
    }

    pair<ll,ll> restaraunt;
    cin >> restaraunt.first >> restaraunt.second;

    ll sz = n + n+m-1 +2;
    ::n = sz;
    ::m = sz;

	vector<vector<edge>> g(::n);

    ll s = sz - 1;
    ll t = sz - 2;

    // Connect source to each bottle
    for(ll i = 0; i < n; i++) {
        addedge(g,s,i,1,0);
    }

    // Connect each courier to the sink
    for(ll j = 0; j < n+m-1; j++) {
        ll a = j+n;
        addedge(g,a,t,1,0);
    }

    // For each bottle
    for(ll i = 0; i < n; i++) {
        // For each courier
        for(ll j = 0; j < n+m-1; j++) {
            ll a = j + n;
            // Actual courier
            if(j < m) {
                ll costhere = 0;
                costhere += dist(bottles[i],couriers[j]);
                costhere += dist(bottles[i],restaraunt);
                addedge(g,i,a,1,costhere);
            }
            // Restaraunt and back
            else {
                ll costhere = 0;
                costhere += 2 * dist(bottles[i],restaraunt);
                addedge(g,i,a,1,costhere);
            }
        }
    }

    pair<ll,ll> p1 = mincostflow(g, s, t);
    cout << p1.second << endl;
}
