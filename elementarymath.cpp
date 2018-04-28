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





bool match(ll curr, vector<vector<ll>>& adj, vector<ll>& l, vector<ll>& r, vector<ll>& vis) {
    if(vis[curr]) return false;
    vis[curr] = true;

    for(auto next : adj[curr]) {
        if(r[next] == -1 || match(r[next], adj, l, r, vis)) {
            l[curr] = next;
            r[next] = curr;
            return true;
        }
    }
    return false;
}

vector<ll> bipartite(vector<vector<ll>>& adj, ll n, ll m) {
    vector<ll> l, r, vis;
    l.resize(n, -1);
    r.resize(m, -1);
    vis.resize(n);

    bool works = true;
    while(works) {
        works = false;
        fill(vis.begin(), vis.end(), 0);
        for(ll i = 0; i < n; i++) {
            if(l[i] == -1) {
                works |= match(i, adj, l, r, vis);
            }
        }
    }

    return l;
}

void makework(ll l, ll r, ll end) {
    cout << l << " ";

    if(l+r == end) {
        cout << "+";
    }
    else if(l - r == end) {
        cout << "-";
    }
    else {
        cout << "*";
    }

    cout << " " << r << " = " << end << endl;
}

int main() {
    //file();
    fast();

    ll n;
    cin >> n;
    vector<pair<ll,ll>> input;
    vector<vector<ll>> adj(n);

    map<ll,ll> numtonode;
    vector<ll>  nodetonum;
    ll rcount = 0;

    for(ll i = 0; i < n; i++) {
        pair<ll,ll> p;
        cin >> p.first >> p.second;
        input.pb(p);

        ll num1 = p.first + p.second;
        if(numtonode.count(num1) == 0) {
            numtonode[num1] = rcount;
            nodetonum.pb(num1);
            rcount++;
        }

        ll num2 = p.first - p.second;
        if(numtonode.count(num2) == 0) {
            numtonode[num2] = rcount;
            nodetonum.pb(num2);
            rcount++;
        }

        ll num3 = p.first * p.second;
        if(numtonode.count(num3) == 0) {
            numtonode[num3] = rcount;
            nodetonum.pb(num3);
            rcount++;
        }

        adj[i].pb(numtonode[num1]);
        adj[i].pb(numtonode[num2]);
        adj[i].pb(numtonode[num3]);
    }

    vector<ll> matching = bipartite(adj, n, rcount);

    ll total = 0;
    for(ll i = 0; i < n; i++) {
        total += (matching[i] != -1);
    }

    if(total == n) {
        for(ll i = 0; i < n; i++) {
            makework(input[i].first, input[i].second, nodetonum[matching[i]]);
        }
    }
    else {
        cout << "impossible" << endl;
    }

    return 0;
}
