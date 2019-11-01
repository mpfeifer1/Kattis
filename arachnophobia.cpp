#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = (ll)1 << 62;

ll n, m, targettime;
ll snode, enode;

// Returns true if there's a path from start to end with time <= targettime, and with a distance of
// at least dist from a spider
bool path(vector<vector<pair<ll,ll>>>& adj, ll dist, vector<ll>& distspider) {
	// if clearly impossible, don't try
	if(distspider[snode] < dist) return false;
	if(distspider[enode] < dist) return false;

	// If the spider is too close, we can't go there
	vector<bool> vis(n,false);
	for(ll i = 0; i < n; i++) {
		if(distspider[i] < dist) vis[i] = true;
	}

	vector<ll> besttime(n,inf);
	besttime[snode] = 0;

	// {-weight,dest}
	priority_queue<pair<ll,ll>> q;
	q.push({0,snode});

	while(!q.empty()) {
		ll curr = q.top().second;
		q.pop();

		if(vis[curr]) continue;
		vis[curr] = true;

		for(auto [next,weight] : adj[curr]) {
			if(!vis[next] && besttime[next] > besttime[curr] + weight) {
				besttime[next] = besttime[curr] + weight;
				q.push({-besttime[next],next});
			}
		}
	}
	
	return besttime[enode] <= targettime;
}

int main() {
	// Read in basic info
	cin >> n >> m >> targettime;

	// Read in graph
	// {dest,weight}
	vector<vector<pair<ll,ll>>> adj(n);
	for(ll i = 0; i < m; i++) {
		ll u, v, w;
		cin >> u >> v >> w;

		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}

	// Read in start and end point
	cin >> snode >> enode;

	// Read in the spiders
	ll numspiders;
	cin >> numspiders;
	vector<ll> spiders(numspiders);
	for(auto& i : spiders) cin >> i;

	// Run dijkstra's to get closest spider for each node
	vector<ll> distspider(n,inf);
	vector<bool> visspider(n,false);
	// {-weight,dest}
	priority_queue<pair<ll,ll>> spider_queue;
	for(auto i : spiders) {
		distspider[i] = 0;
		spider_queue.push({0,i});
	}

	while(!spider_queue.empty()) {
		ll curr = spider_queue.top().second;
		spider_queue.pop();

		if(visspider[curr]) continue;
		visspider[curr] = true;

		for(auto [next,weight] : adj[curr]) {
			if(distspider[next] > distspider[curr] + weight) {
				distspider[next] = distspider[curr] + weight;
				spider_queue.push({-distspider[next],next});
			}
		}
	}

	// Binary search on the best distance from a spider
	ll lo = 0;
	ll hi = inf;
	ll ans = 0;

	while(hi - lo >= 0) {
		ll mi = (hi + lo) / 2;
		if(path(adj, mi, distspider)) {
			lo = mi+1;
			ans = max(ans,mi);
		}
		else {
			hi = mi-1;
		}
	}

	cout << ans << endl;
}
