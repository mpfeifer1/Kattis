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





int n;

struct swp {
    int l, r;
};

void runswap(vector<int>& v, vector<swp>& swaps, int lo, int hi) {
    if((hi - lo) % 2 == 0) {
        //cout << "not divisible by two" << endl;
        return;
    }
    if(lo < 0 || hi < 0) {
        //cout << "too low" << endl;
        return;
    }
    if(hi >= n || lo >= n) {
        //cout << "too high" << endl;
        return;
    }
    if(lo >= hi) {
        //cout << "swapped" << endl;
        return;
    }

    /*
    cout << "Befor: ";
    for(auto i : v) {
        cout << i << " ";
    }
    cout << endl;
    */

    swp s;
    s.l = lo;
    s.r = hi;
    swaps.pb(s);

    int len = (hi-lo+1) / 2;
    for(int i = lo; i < lo+len; i++) {
        swap(v[i], v[i+len]);
    }

    /*
    cout << "After: ";
    for(auto i : v) {
        cout << i << " ";
    }
    cout << endl << endl;
    */
}

void cranesort(vector<int>& v, vector<swp>& swaps) {
    for(int i = 0; i < n; i++) {
        //cout << "Processing " << i << endl;
        // Find current number - make faster???
        int pos;
        for(pos = i; pos < n; pos++) {
            if(v[pos] == i) {
                break;
            }
        }

        // If sorted, quit
        if(pos == i) {
            continue;
        }

        // If in back half, swap to front
        if(pos > (i+n-1)/2) {
            //cout << "in back half" << endl;
            if((n - i) % 2 == 0) {
                runswap(v, swaps, i, n-1);
            }
            else {
                runswap(v, swaps, i+1, n-1);
            }
        }

        // Find position again
        for(pos = i; pos < n; pos++) {
            if(v[pos] == i) {
                break;
            }
        }

        // If sorted, quit
        if(pos == i) {
            continue;
        }

        // Swap into correct spot
        int endpoint = ((pos-i-1)*2) + i+1;
        if((endpoint-i)%2 == 0) {
            endpoint--;
        }
        runswap(v, swaps, i, endpoint);

        //cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }
}

int main() {
    //file();
    //fast();

    int cases;
    cin >> cases;

    while(cases--) {
        cin >> n;

        vector<int> v(n);
        for(auto& i : v) {
            cin >> i;
            i--;
        }

        /*
        for(auto& i : v) {
            cout << i << " ";
        }
        cout << endl;
        */

        vector<swp> swaps;
        cranesort(v, swaps);

        /*
        for(auto i : v) {
            cout << i << " ";
        }
        cout << endl;
        */

        cout << swaps.size() << endl;
        for(auto i : swaps) {
            cout << i.l+1 << " " << i.r+1 << endl;
        }
    }

    return 0;
}
