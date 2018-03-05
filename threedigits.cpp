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





ll compress(ll n) {
    while(n % 10 == 0) {
        n /= 10;
    }
    return n;
}

int main() {
    //file();
    //fast();

    ll n;
    cin >> n;

    ll ans = 1;
    ll fives = 0;
    ll twos = 0;
    for(ll i = 1; i <= n; i++) {
        ans *= compress(i);
        while(ans % 5 == 0) {
            ans /= 5;
            fives++;
        }
        while(ans % 2 == 0) {
            ans /= 2;
            twos++;
        }
        ans %= 100000;
    }

    twos -= fives;
    while(twos--) {
        ans *= 2;
        ans %= 1000;
    }

    if(n > 6 && ans < 100) {
        cout << "0";
        if(ans < 10) {
            cout << "0";
        }
    }
    cout << ans%1000 << endl;

    return 0;
}
