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
    //fast();

    int n, m;
    cin >> n >> m;

    vector<vector<char>> v;
    v.resize(n+2, vector<char>(m+2,'X'));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }

    vector<vector<int>> height;
    height.resize(n+2, vector<int>(m+2,0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(v[i][j] != 'X') {
                height[i][j] = height[i-1][j] + 1;
            }
        }
    }

    /*
    for(int i = 0; i < n+2; i++) {
        for(int j = 0; j < m+2; j++) {
            cout << height[i][j] << " ";
        }
        cout << endl;
    }
    */

    int ans = 0;
    for(int h = 1; h <= 1000; h++) {

        for(int i = 1; i <= n; i++) {
            int len = 0;
            for(int j = 1; j <= m; j++) {
                if(height[i][j] >= h) {
                    len++;
                    ans = max(ans, 2*(len+h));
                }
                else {
                    len = 0;
                }
            }
        }

    }

    cout << ans-1 << endl;

    return 0;
}
