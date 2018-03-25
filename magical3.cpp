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





vector<ll> primefactors(ll n) {
    vector<ll> v;
    for(int i = 2; i <= sqrt(n); i++) {
        while(n % i == 0) {
            n /= i;
            v.pb(i);
        }
    }
    if(n > 1) {
        v.pb(n);
    }
    return v;
}

ll getbase(ll n) {
    if(n == 3) {
        return 4;
    }
    if(n < 7) {
        return -1;
    }

    vector<ll> factors = primefactors(n-3);
    ll best = inf;

    // Grab the best single factor
    for(int i = 0; i < factors.size(); i++) {
        if(factors[i] > 3) {
            best = min(best, factors[i]);
            break;
        }
    }

    // Grab the best compound factor
    if(factors.size() >= 2) {
        best = min(best, factors[0] * factors[1]);
    }

    return best;
}

int main() {
    //file();
    //fast();

    ll n;
    while(cin >> n && n != 0) {
        ll base = getbase(n);
        if(base == -1) {
            cout << "No such base" << endl;
        }
        else {
            cout << base << endl;
        }
    }

    return 0;
}
