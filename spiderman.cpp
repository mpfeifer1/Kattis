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





struct state {
    int h;
    string p;
};

bool operator < (const state& lhs, const state& rhs) {
    return lhs.h < rhs.h;
}

state getstate(state oldstate, int currheight, int dir) {
    state newstate;
    newstate.h = max(currheight, oldstate.h);
    if(dir == 1) {
        newstate.p = oldstate.p + "U";
    }
    if(dir == -1) {
        newstate.p = oldstate.p + "D";
    }
    return newstate;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    int remaining = 0;
    for(auto& i : v) {
        cin >> i;
        remaining += i;
    }

    map<int,state> curr;
    curr[0] = {0,""};

    for(auto i : v) {
        map<int,state> next;
        remaining -= i;

        for(auto j : curr) {
            int hi = j.first + i;
            state s1 = getstate(j.second, hi, 1);
            if(next.count(hi) == 0) {
                next[hi] = s1;
            }
            else {
                next[hi] = min(next[hi], s1);
            }

            int lo = j.first - i;
            state s2 = getstate(j.second, lo, -1);
            if(next.count(lo) == 0) {
                next[lo] = s2;
            }
            else {
                next[lo] = min(next[lo], s2);
            }
        }

        // Clear out all negative and all greater than remaining sum
        map<int,state> actual;
        for(auto i : next) {
            if(i.first <= remaining && i.first >= 0) {
                actual[i.first] = i.second;
            }
        }

        curr = actual;
    }

    if(curr.count(0) > 0) {
        cout << curr[0].p << endl;
    }
    else {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main() {
    //file();
    //fast();

    int cases;
    cin >> cases;
    while(cases--) {
        solve();
    }

    return 0;
}
