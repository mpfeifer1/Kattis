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





vector<ll> getpath(ll n) {
    vector<ll> res;

    while(n != 1) {
        res.pb(n);

        if(n%2 == 0) {
            n /= 2;
        }
        else {
            n *= 3;
            n++;
        }
    }

    res.pb(1);
    return res;
}

int main() {
    //file();
    //fast();

    ll n, m;
    while(cin >> n && cin >> m) {
        if(n == 0 && m == 0) {
            break;
        }

        vector<ll> p1 = getpath(n);
        vector<ll> p2 = getpath(m);

        ll lastsimilar = 1;
        while(p1.size() > 0 && p2.size() > 0 && p1.back() == p2.back()) {
            lastsimilar = p1.back();
            p1.pop_back();
            p2.pop_back();
        }

        cout << n << " needs " << p1.size() << " steps, ";
        cout << m << " needs " << p2.size() << " steps, ";
        cout << "they meet at " << lastsimilar << endl;
    }

    return 0;
}
