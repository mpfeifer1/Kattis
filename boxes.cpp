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
const ll  inf  = 1e18 + 10;
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








struct dt {
    int idx;
    int depth;
    dt(int i, int j) {idx = i; depth = j;};
};

struct dp
{
    dt val;
    dp(): val(iinf, iinf) {};
    dp(dt i): val(i.idx, i.depth) {};
    void update(const dt &u)
    {
        //we may want to add, set, multiply, etc
        val = u;
    }
};

dp combine(dp l, dp r)
{
    //we may want to add, multiply, xor, etc
    if(l.val.depth < r.val.depth) {
        return l;
    }
    return r;
}

struct segment
{
    //segment tree for dp with point updates and range queries
    vector<dp> data;
    int s;
    segment(int sz, const vector<dp> &base = vector<dp>()): s(sz)
    {
        //first s elements are our tree, next s are the array, 0 unused
        //each node i has children 2i and 2i+1
        data.resize(2 * s);
        for(int i = 0; i < base.size(); i++)
        {
            data[s+i] = base[i];
        }
        for(int i = s - 1; i > 0; i--)
        {
            data[i] = combine(data[2*i], data[2*i+1]);
        }
    }
    void update(int spot, const dt &update)
    {
        data[spot + s].update(update);
        //walk back through parents and recombine each
        for(int i = (spot + s) / 2; i > 0; i /= 2)
            data[i] = combine(data[2*i], data[2*i+1]);
    }
    dp query(int si, int ei)
    {
        dp res;
        //[si, ei) are edges at this level.
        //when last bit is set parent may include extra that we don't want
        //so add this subtree into result now and exclude it at higher levels
        for(si += s, ei += s; si < ei; si /= 2, ei /= 2)
        {
            if(si % 2 == 1)
                res = combine(res, data[si++]);
            if(ei % 2 == 1)
                res = combine(res, data[--ei]);
        }
        return res;
    }
};



// DFS to get count for node
void getcount(vector<vector<int>>& adj, vector<int>& c, int i, vector<int>& d, int currdepth) {
    d[i] = currdepth;

    if(adj[i].size() == 0) {
        c[i] = 1;
        return;
    }

    int total = 1;
    for(auto j : adj[i]) {
        getcount(adj, c, j, d, currdepth + 1);
        total += c[j];
    }

    c[i] = total;
}

// Traverse tree
void trav(vector<vector<int>>& adj, vector<int>& traverse, vector<int>& first, int curr) {
    first[curr] = traverse.size();
    traverse.pb(curr);
    for(auto next : adj[curr]) {
        trav(adj, traverse, first, next);
        traverse.pb(curr);
    }
}

int find(vector<int>& d, int a) {
    if(d[a] == -1) {
        return a;
    }
    return d[a] = find(d, d[a]);
}

void join(vector<int>& d, int a, int b) {
    a = find(d, a);
    b = find(d, b);
    if(a == b) return;
    d[a] = b;
}

int main() {
    //file();
    fast();

    int n;
    cin >> n;

    // Allocate storage
    vector<int> d(n); // Depth
    vector<int> c(n); // Count
    vector<int> top; // Nums of all roots
    vector<vector<int>> adj(n); // Adjacency matrix
    vector<int> disjoint(n, -1); // All trees indexes

    // Read in input
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if(t != 0) {
            t--;
            adj[t].pb(i);
            join(disjoint, i, t);
        }
        else {
            top.pb(i);
        }
    }

    // Build count array
    for(auto i : top) {
        getcount(adj, c, i, d, 0);
    }

    // Build LCA array
    vector<int> traverse; // Index of each node in tour
    vector<int> depth; // Depth of each node in tour
    vector<int> first(n); // First time each node is seen
    for(auto i : top) {
        trav(adj, traverse, first, i);
    }
    for(auto i : traverse) {
        depth.pb(d[i]);
    }

    // Make LCA array a segment tree
    vector<dp> init;
    for(int i = 0; i < traverse.size(); i++) {
        dp here;
        here.val.idx = traverse[i];
        here.val.depth = depth[i];
        init.pb(here);
    }
    segment segtree(init.size(), init);

    // Run each query
    int queries;
    cin >> queries;
    while(queries--) {
        int z;
        cin >> z;

        // Read in boxes
        set<int> tmp;
        for(int i = 0; i < z; i++) {
            int t; cin >> t; t--;
            tmp.insert(t);
        }

        // Remove duplicate boxes
        vector<int> q;
        for(auto i : tmp) q.pb(i);
        z = q.size();

        // Check if boxes aren't valid
        vector<bool> valid(z, true);
        for(int i = 0; i < z; i++) {
            for(int j = 0; j < i; j++) {
                if(find(disjoint, q[i]) != find(disjoint, q[j])) continue;
                int b1 = first[q[i]];
                int b2 = first[q[j]];
                if(b1 > b2) swap(b1, b2);
                int parent = segtree.query(b1,b2+1).val.idx;
                if(parent == q[i]) valid[j] = false;
                if(parent == q[j]) valid[i] = false;
            }
        }

        // Calculate and print answer
        int cost = 0;
        for(int i = 0; i < z; i++) {
            if(valid[i]) {
                cost += c[q[i]];
            }
        }
        cout << cost << endl;
    }

    return 0;
}
