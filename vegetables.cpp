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





struct veg {
    ll len;
    ll cut;
    int idx;
};

struct cmp {
    bool operator() (const veg& lhs, const veg& rhs) const {
        ld l = (ld(lhs.len)/(lhs.cut+1));
        ld r = (ld(rhs.len)/(rhs.cut+1));

        if(abs(l-r) < prec) {
            if(lhs.len == rhs.len) {
                return lhs.idx < rhs.idx;
            }
            return lhs.len > rhs.len;
        }
        return l < r;
    }
};

ld vegratio(veg v1, veg v2) {
    ld lo = (v1.len/(v1.cut+1));
    ld hi = (v2.len/(v2.cut+1));

    return lo / hi;
}

int main() {
    //file();
    //fast();

    ld r;
    ll n;
    cin >> r >> n;

    set<veg, cmp> s;
    for(int i = 0; i < n; i++) {
        veg v;
        cin >> v.len;
        v.cut = 0;
        v.idx = i;
        s.insert(v);
    }

    int cuts = 0;
    while(vegratio(*s.begin(), *prev(s.end())) < r) {
        veg v = *prev(s.end());
        s.erase(v);

        v.cut++;
        cuts++;

        s.insert(v);
    }

    cout << cuts << endl;

    return 0;
}
