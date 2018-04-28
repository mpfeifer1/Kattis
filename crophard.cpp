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

    vector<vector<ll>> points;
    points.resize(3, vector<ll>(3,0));

    ll x = x0;
    ll y = y0;
    points[x%3][y%3]++;
    for(ll i = 1; i < n; i++) {
        x = (a*x+b)%m;
        y = (c*y+d)%m;
        points[x%3][y%3]++;
    }

    ll total = 0;
    for(ll i = 0; i < 9; i++) {
        ll val = points[i/3][i%3];
        total += val * (val-1) * (val-2) / 6;
    }

    for(ll i = 0; i < 9; i++) {
        for(ll j = i+1; j < 9; j++) {
            for(ll k = j+1; k < 9; k++) {
                ll xval = (i/3)+(j/3)+(k/3);
                ll yval = (i%3)+(j%3)+(k%3);
                if(xval % 3 == 0 && yval % 3 == 0) {
                    total += points[i/3][i%3] *
                             points[j/3][j%3] *
                             points[k/3][k%3];
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
