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





void getval(vector<int>& v, vector<int>& ret, int subset) {
    int curr = 0;
    while(subset > 0) {
        if(subset % 2 == 1) {
            ret.pb(v[curr]);
        }
        subset >>= 1;
        curr++;
    }
}

int getsum(vector<int>& v, int subset) {
    vector<int> vals;
    getval(v, vals, subset);
    int total = 0;
    for(auto i : vals) {
        total += i;
    }
    return total;
}

int main() {
    //file();
    fast();

    int cases;
    cin >> cases;

    for(int casenum = 0; casenum < cases; casenum++) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(auto& i : v) {
            cin >> i;
        }

        // Maps sum to subset value
        map<int,int> m;
        for(int i = 0; i < (1<<n); i++) {
            int sum = getsum(v, i);

            if(m.count(sum) > 0 && (m[sum] ^ i) != 0) {
                cout << "Case #" << casenum+1 << ":" << endl;
                vector<int> set1;
                getval(v, set1, i);
                for(auto i : set1) {
                    cout << i << " ";
                }
                cout << endl;
                vector<int> set2;
                getval(v, set2, m[sum]);
                for(auto i : set2) {
                    cout << i << " ";
                }
                cout << endl;
                break;
            }

            m[sum] = i;
        }
    }

    return 0;
}
