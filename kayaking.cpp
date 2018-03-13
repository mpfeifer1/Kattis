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




ll b, n, e;
ll bval, nval, eval;

vector<pair<ll,string>> speeds;
void prep() {
    speeds.pb({bval+bval, "bb"});
    speeds.pb({bval+nval, "bn"});
    speeds.pb({bval+eval, "be"});
    speeds.pb({nval+nval, "nn"});
    speeds.pb({nval+eval, "ne"});
    speeds.pb({eval+eval, "ee"});

    sort(all(speeds));
}

void dec(string s, ll& tb, ll& tn, ll& te) {
    for(auto i : s) {
        if(i == 'b') {
            tb--;
        }
        if(i == 'n') {
            tn--;
        }
        if(i == 'e') {
            te--;
        }
    }
}

bool ok(string s, ll tb, ll tn, ll te) {
    dec(s, tb, tn, te);
    return (tb >= 0) && (tn >= 0) && (te >= 0);
}

bool works(vector<ll> kayaks, ll speed) {
    ll tb = b;
    ll tn = n;
    ll te = e;

    bool works = true;
    for(auto i : kayaks) {
        bool thisworks = false;
        for(auto j : speeds) {
            if(i * j.first >= speed && ok(j.second,tb,tn,te)) {
                dec(j.second, tb, tn, te);
                thisworks = true;
                break;
            }
        }
        if(!thisworks) {
            works = false;
            break;
        }
    }

    return works;
}

int main() {
    //file();
    //fast();

    cin >> b >> n >> e;
    cin >> bval >> nval >> eval;

    vector<ll> kayaks((b+n+e)/2);
    for(auto& i : kayaks) {
        cin >> i;
    }
    sort(all(kayaks));
    reverse(all(kayaks));

    prep();

    ll lo = 0;
    ll hi = (ll)100000 * 1000 * 2 * 100;
    while(hi-lo>1) {
        ll mi = (hi+lo)/2;
        if(works(kayaks,mi)) {
            lo = mi;
        }
        else {
            hi = mi;
        }
    }

    cout << lo << endl;

    return 0;
}
