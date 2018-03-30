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
const ld  prec = .00000000001;

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





// Define math functions
ld e_cosh(ld x) {
    return (pow(M_E, x) + pow(M_E, -x)) / 2;
}

ld e_sinh(ld x) {
    return (pow(M_E, x) - pow(M_E, -x)) / 2;
}

// Returns true if long enough
bool check(ld d, ld s, ld a) {
    // given distance between, sag desired, and 'a'

    ld lhs = a + s;
    ld rhs = a * cosh(d / (2*a));
    return rhs <= lhs;
}

int main() {
    //file();
    //fast();

    ld d, s;
    cin >> d >> s;

    ld lo = 0;
    ld hi = inf;

    while(hi-lo>prec) {
        ld mi = (hi+lo) / 2;
        if(check(d, s, mi)) {
            hi = mi;
        }
        else {
            lo = mi;
        }
    }

    ld a = lo;
    ld ans = 2*a * sinh(d/(2*a));

    cout << fixed;
    cout.precision(8);
    cout << ans << endl;

    return 0;
}
