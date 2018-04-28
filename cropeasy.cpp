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




void solve() {
    ll n, a, b, c, d, x0, y0, m;
    cin >> n >> a >> b >> c >> d >> x0 >> y0 >> m;

    vector<pair<ll,ll>> points;
    set<pair<ll,ll>> pointsset;

    ll x = x0;
    ll y = y0;
    points.pb({x,y});
    for(ll i = 1; i < n; i++) {
        x = (a*x+b)%m;
        y = (c*y+d)%m;
        points.pb({x,y});
    }

    for(auto i : points) {
        pointsset.insert(i);
    }

    ll total = 0;
    for(ll i = 0; i < n; i++) {
        for(ll j = i+1; j < n; j++) {
            for(ll k = j+1; k < n; k++) {
                ll sumx = points[i].first +
                          points[j].first +
                          points[k].first;
                ll sumy = points[i].second +
                          points[j].second +
                          points[k].second;
                if(sumx % 3 == 0 && sumy % 3 == 0) {
                    total++;
                }
            }
        }
    }

    cout << total << endl;
}

int main() {
    //file();
    //fast();

    ll cases;
    cin >> cases;
    for(ll i = 1; i <= cases; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
