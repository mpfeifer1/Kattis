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
const ll  inf  = 1e18 + iinf + 10;
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





int main() {
    //file();
    //fast();

    ll n;
    cin >> n;

    // Maps val to original pos
    map<ll,ll> m;

    // Contains {original pos, val}
    indexed_set<pair<ll,ll>> s;

    for(ll i = 0; i < n; i++) {
        ll n1;
        cin >> n1;
        s.insert({i, n1});
        m[n1] = i;
    }

    /*
    for(auto i : s) {
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;
    */

    ll moves = 0;
    ll pos = 0; // our ACTUAL position in the array
    ll nextball = 1;
    while(s.size() > 0) {
        // Find next ball
        ll orig = m[nextball];
        pair<ll,ll> here = *s.lower_bound({orig,-1});
        //cout << "Orig location is " << orig << endl;
        //cout << here.first << " " << here.second << endl;

        // Count rotations to it
        ll loc = s.order_of_key(here);
        ll sz = s.size();
        ll m1 = ((loc - pos) + sz) % sz;
        ll m2 = ((pos - loc) + sz) % sz;
        moves += min(m1,m2);
        pos = loc;
        //cout << "Added " << min(m1,m2) << endl;

        // Drop ball
        s.erase(here);
        moves++;

        // Choose next ball to drop
        nextball++;
    }

    cout << moves << endl;

    return 0;
}
