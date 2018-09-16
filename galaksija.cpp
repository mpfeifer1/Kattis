#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// Edge struct
struct edge {
    ll n1;
    ll n2;
    ll xval;
};

// Disjoint set find
ll find(vector<ll>& d, ll a) {
    if(d[a] == -1) return a;
    return d[a] = find(d, d[a]);
}

// Disjoint set join (sets B to representative)
void join(vector<ll>& d, ll a, ll b) {
    a = find(d, a);
    b = find(d, b);
    if(a == b) return;
    d[a] = b;
}

// DFS and set XOR vals as we go
void dfs(vector<vector<pair<ll,ll>>>& adj, vector<bool>& vis, vector<ll>& xorarr, ll curr) {
    vis[curr] = true;

    for(auto& i : adj[curr]) {
        ll next = i.first;
        ll val = i.second;

        if(!vis[next]) {
            xorarr[next] = xorarr[curr] ^ val;
            dfs(adj, vis, xorarr, next);
        }
    }
}

// Merge set sm into set lg, return paths added
ll merge(map<ll,ll>& sm, map<ll,ll>& lg) {
    // Calculate all vals, add to update patch
    map<ll,ll> update;
    ll ans = 0;
    for(auto& i : sm) {
        ll xval = i.first;
        ans += sm[xval] * lg[xval];
        update[xval] = sm[xval] + lg[xval];
    }

    // Use update patch to fix large set
    for(auto& i : update) {
        lg[i.first] = i.second;
    }

    // Return answer
    return ans;
}

int main() {
    // Fast IO
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // Read in input
    ll n;
    cin >> n;

    // Build adjacency list
    vector<vector<pair<ll,ll>>> adj(n);

    // Build edge list
    vector<edge> edges;
    for(ll i = 0; i < n-1; i++) {
        edge e;
        cin >> e.n1 >> e.n2 >> e.xval;
        e.n1--;
        e.n2--;
        edges.push_back(e);

        adj[e.n1].push_back({e.n2,e.xval});
        adj[e.n2].push_back({e.n1,e.xval});
    }

    // Read in permutation
    vector<ll> order;
    for(ll i = 0; i < n-1; i++) {
        ll t;
        cin >> t;
        t--;
        order.push_back(t);
    }

    // DFS to give all nodes their XOR parities
    vector<bool> vis(n,false);
    vector<ll> xorarr(n,0);
    dfs(adj, vis, xorarr, 0);

    // Build a set for each group
    vector<map<ll,ll>> sets(n);
    for(ll i = 0; i < n; i++) {
        sets[i][xorarr[i]] = 1;
    }

    // Prepare answer
    deque<ll> ans = {0};

    // Go in reverse order joining sets
    vector<ll> d(n, -1);
    for(ll i = n-2; i >= 0; i--) {
        // Grab two indices, get parents
        ll n1 = find(d, edges[order[i]].n1);
        ll n2 = find(d, edges[order[i]].n2);

        // Set n2 as the parent
        join(d, n1, n2);

        // Make sure n2 is the larger set
        if(sets[n1].size() > sets[n2].size()) {
            swap(sets[n1], sets[n2]);
        }

        // Merge n1 into set n2
        ll val = merge(sets[n1], sets[n2]);

        // Tack on additional value
        ans.push_front(ans.front() + val);
    }

    // Print out answers in reverse
    for(auto i : ans) {
        cout << i << endl;
    }
}
