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





ll find(vector<ll>& d, ll a) {
    if(d[a] == -1) {
        return a;
    }
    return d[a] = find(d, d[a]);
}

void join(vector<ll>& d, ll a, ll b) {
    a = find(d, a);
    b = find(d, b);
    if(a == b) return;
    d[a] = b;
}

bool inrange(int n, int i) {
    return i >= 0 && i < n;
}

void sieve(vector<ll>& primes) {
    bool p[1000001];
    for(int i = 0; i <= 1000000; i++) {
        p[i] = true;
    }

    p[0] = false;
    p[1] = false;

    for(int i = 0; i <= 1000000; i++) {
        if(p[i]) {
            primes.pb(i);
            for(int j = i*2; j <= 1000000; j += i) {
                p[j] = false;
            }
        }
    }
}

ll solve() {
    ll a, b, p;
    cin >> a >> b >> p;

    vector<ll> d(b-a+1);
    for(ll i = 0; i <= b-a; i++) {
        d[i] = -1;
    }

    vector<ll> primes;
    sieve(primes);

    for(auto i : primes) {
        if(i < p) continue;
        for(ll j = (a/i)*i; j <= b; j+=i) {
            if(inrange(b-a+1, j-a) && inrange(b-a+1, j-i-a)) {
                join(d, j-a, j-i-a);
            }
        }
    }

    ll sets = 0;
    for(ll i = 0; i <= b-a; i++) {
        if(d[i] == -1) {
            sets++;
        }
    }

    return sets;
}

int main() {
    //file();
    fast();

    ll cases;
    cin >> cases;
    for(ll i = 1; i <= cases; i++) {
        cout << "Case #" << i << ": " << solve() << endl;
    }

    return 0;
}
