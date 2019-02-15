#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = (ll)1 << 60;

ll best_dist = inf;
vector<ll> best;
ll total_locs;

ll dfs(ll curr, ll dist, vector<vector<pair<ll,ll>>>& adj, vector<ll>& size, vector<ll>& sub_size, vector<bool>& vis) {
    if(vis[curr]) return 0;
    vis[curr] = true;

    ll res = size[curr] * dist;
    for(auto i : adj[curr]) {
        ll next = i.first;
        ll weight = i.second;
        if(!vis[next]) {
            res += dfs(next, dist+weight, adj, size, sub_size, vis);
            sub_size[curr] += sub_size[next];
        }
    }
    sub_size[curr] += size[curr];
    return res;
}

void reroot(ll curr, ll ans, vector<vector<pair<ll,ll>>>& adj, vector<ll>& size, vector<ll>& sub_size, vector<bool>& vis) {
    if(vis[curr]) return;
    vis[curr] = true;

    if(ans < best_dist) {
        best.clear();
        best_dist = ans;
    }
    if(ans == best_dist) {
        best.push_back(curr+1);
    }

    for(auto i : adj[curr]) {
        ll next = i.first;
        ll weight = i.second;

        ll new_ans = ans;

        ll sub = sub_size[next] * weight;
        ll add = (total_locs - sub_size[next]) * weight;

        new_ans -= sub;
        new_ans += add;

        reroot(next, new_ans, adj, size, sub_size, vis);
    }
}

void solve() {
    best_dist = inf;
    best.clear();
    total_locs = 0;

    ll n;
    cin >> n;

    // {dest,weight}
    vector<vector<pair<ll,ll>>> adj(n);
    for(ll i = 0; i < n-1; i++) {
        ll a, b, t;
        cin >> a >> b >> t;
        a--; b--;
        t *= 2;
        adj[a].push_back({b,t});
        adj[b].push_back({a,t});
    }

    // Read in how many times each node must be visited
    vector<ll> size(n,0);
    ll m;
    cin >> m;
    for(ll i = 0; i < m; i++) {
        ll a, t;
        cin >> a >> t;
        a--;
        size[a] += t;
        total_locs += t;
    }

    // Calculate all the subtree sizes, and the initial answer
    vector<ll> sub_size(n,0);

    // Solve the problem for one root
    vector<bool> vis(n,false);
    ll ans = dfs(0,0,adj,size,sub_size,vis);

    // Reroot at any point
    vis.clear();
    vis.resize(n,false);
    reroot(0,ans,adj,size,sub_size,vis);

    // Print the answer
    cout << best_dist << endl;
    sort(best.begin(),best.end());
    for(auto i : best) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    ll cases;
    cin >> cases;

    while(cases--) {
        solve();
    }
}
