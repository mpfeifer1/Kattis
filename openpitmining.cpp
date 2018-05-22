// Michael Pfeifer
// Version 04, 2018/02/17

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const ld  pi   = 4.0*atanl(1.0);
const int iinf = 1e9 + 10;
const ll  inf  = 1e18 + iinf + 10;
const int mod  = 1000000007;
const ld  prec = .000001;

#define enld endl
#define endl '\n'
#define pb push_back
#define debug(x) cout<<#x<<" -> "<<x<<'\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define umap unordered_map
#define uset unordered_set

template<class TIn>
using indexed_set = tree<
        TIn, null_type, less<TIn>,
        rb_tree_tag, tree_order_statistics_node_update>;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void file() {
    auto a = freopen("a.in",  "r", stdin);
    auto b = freopen("a.out", "w", stdout);
    if(!a || !b) cout << "uh oh" << endl;
}





const int SIZE = 202;

ll bfs(vector<vector<ll>>& og, vector<vector<ll>>& rg, vector<ll>& par, ll s, ll t, ll n) {
    vector<ll> f(SIZE, 0);

    vector<bool> visited(SIZE, false);
    visited[s] = true;

    queue<ll> q;
    q.push(s);
    par[s] = -1;
    f[s] = inf;

    while(!q.empty()) {
        ll u = q.front();
        q.pop();
        for(ll v = 0; v < n; v++) {
            if(visited[v] == false && rg[u][v] > 0) {
                q.push(v);
                par[v] = u;
                visited[v] = true;
                f[v] = min(f[u], rg[u][v]);
            }
        }
    }

    if(visited[t]) {
        return f[t];
    }
    return 0;
}

// Takes in original graph, residual graph, source, sink, #nodes
ll fulkerson(vector<vector<ll>>& og, vector<vector<ll>>& rg, ll s, ll t, ll n) {
    ll max_flow = 0, path_flow = 0;

    vector<ll> par(SIZE);

    while(path_flow = bfs(og, rg, par, s, t, n)) {
        for(ll v = t; v != s; v = par[v]) {
            ll u = par[v];
            rg[u][v] -= path_flow;
            rg[v][u] += path_flow;
        }
        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    //file();
    //fast();

    // Set up original graph and residual graph
    vector<vector<ll>> og, rg;
    og.resize(SIZE, vector<ll>(SIZE, 0));
    rg.resize(SIZE, vector<ll>(SIZE, 0));

    // Allocate storage
    vector<vector<int>> adj(SIZE);
    vector<int> profit(SIZE);
    int sum = 0;

    // Read in input
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int v, c;
        cin >> v >> c;
        int p;
        p = v - c;
        profit[i] = p;
        if(p > 0) sum += p;

        int children;
        cin >> children;
        while(children--) {
            int n1; cin >> n1;
            adj[i].pb(n1);
        }
    }

    // Convert list to matrix
    for(ll i = 0; i < SIZE; i++) {
        for(auto j : adj[i]) {
            og[j][i] = iinf;
        }
    }

    // Add extra edges to adjacency
    for(int i = 1; i <= n; i++) {
        if(profit[i] >= 0) {
            og[0][i] = profit[i];
        }
        else {
            og[i][201] = -profit[i];
        }
    }

    // Print the answer
    rg = og;
    cout << sum - fulkerson(og, rg, 0, 201, SIZE) << endl;

    return 0;
}
