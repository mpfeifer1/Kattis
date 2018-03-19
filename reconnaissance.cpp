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





struct car {
    ll pos;
    ll vel;
};

ld getpos(car c, ld time) {
    return c.pos + c.vel * time;
}

ld getwindow(vector<car>& v, ld time) {
    ld lo = inf;
    ld hi = -inf;
    for(auto& i : v) {
        ld val = getpos(i, time);
        lo = min(lo, val);
        hi = max(hi, val);
    }

    return hi - lo;
}

int main() {
    //file();
    fast();

    int n;
    cin >> n;

    vector<car> v(n);
    for(auto& i : v) {
        cin >> i.pos >> i.vel;
    }

    ld lo = 0;
    ld hi = 200001;

    while(hi - lo > prec) {
        ld r = (lo+hi*2)/3;
        ld l = (lo*2+hi)/3;

        ld val1 = getwindow(v, l);
        ld val2 = getwindow(v, r);

        if(val1 < val2) {
            hi = r;
        }
        else {
            lo = l;
        }
    }

    cout << fixed;
    cout.precision(5);
    cout << getwindow(v, lo) << endl;

    return 0;
}
