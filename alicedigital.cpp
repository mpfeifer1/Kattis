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





int main() {
    //file();
    fast();

    int cases;
    cin >> cases;

    while(cases--) {
        int n, m;
        cin >> n >> m;

        vector<int> v(n);
        vector<int> idx;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            if(v[i] == m) {
                idx.pb(i);
            }
        }

        int best = 0;
        for(auto i : idx) {
            int total = m;
            for(int j = i-1; j >= 0; j--) {
                if(v[j] <= m) {
                    break;
                }
                total += v[j];
            }
            for(int j = i+1; j < n; j++) {
                if(v[j] <= m) {
                    break;
                }
                total += v[j];
            }
            best = max(best, total);
        }

        cout << best << endl;
    }

    return 0;
}
