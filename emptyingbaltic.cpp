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





ll n, m;

bool inrange(ll x, ll y) {
    if(x < 0 || y < 0 || x >= n || y >= m) {
        return false;
    }
    return true;
}

int main() {
    //file();
    //fast();

    cin >> n >> m;

    vector<vector<ll>> v, best;
    v.resize(n, vector<ll>(m));
    best.resize(n, vector<ll>(m));

    vector<vector<bool>> vis;
    vis.resize(n, vector<bool>(m,false));

    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            cin >> v[i][j];
            if(v[i][j] > 0) {
                v[i][j] = 0;
            }
            v[i][j] = -v[i][j];
            best[i][j] = 0;
        }
    }

    ll x, y;
    cin >> x >> y;
    x--; y--;
    best[x][y] = v[x][y];

    set<pair<ll,pair<ll,ll>>> q;
    q.insert({0,{x,y}});

    vector<pair<ll,ll>> diffs;
    diffs = {{1,1},  {1,0},  {1,-1},
             {0,1},          {0,-1},
             {-1,1}, {-1,0}, {-1,-1}};

    while(!q.empty()) {
        pair<ll,pair<ll,ll>> curr = *prev(q.end());
        q.erase(curr);
        ll currx = curr.second.first;
        ll curry = curr.second.second;

        if(vis[currx][curry]) {
            continue;
        }
        vis[currx][curry] = true;

        for(auto i : diffs) {
            ll nextx = currx + i.first;
            ll nexty = curry + i.second;
            if(inrange(nextx, nexty) && !vis[nextx][nexty]) {
                if(best[currx][curry] > best[nextx][nexty]) {
                    best[nextx][nexty] = max(best[nextx][nexty], min(best[currx][curry], v[nextx][nexty]));
                    q.insert({best[nextx][nexty], {nextx,nexty}});
                }
            }
        }
    }

    ll total = 0;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            //cout << best[i][j] << " ";
            total += best[i][j];
        }
        //cout << endl;
    }

    cout << total << endl;


    return 0;
}
