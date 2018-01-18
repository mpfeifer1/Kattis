// Michael Pfeifer
// Version 02, 2018/01/17

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

#define enld endl
#define endl '\n'
#define pb push_back
#define debug(x) cout<<#x<<" -> "<<x<<'\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define umap unordered_map;
#define uset unordered_set;

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

ll readint(){
    char r;
    bool start=false,neg=false;
    ll ret=0;
    while(true){ r=getchar();
        if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
            continue;
        }
        if((r-'0'<0 || r-'0'>9) && r!='-' && start){
            break;
        }
        if(start)ret*=10;
        start=true;
        if(r=='-')neg=true;
        else ret+=r-'0';
    }
    if(!neg) return ret;
    else return -ret;
}





int main() {
    //file();
    //fast();

    ll n, m, q;
    while(true) {
        // Take in input
        cin >> n >> m >> q;
        if(n == 0 && m == 0 && q == 0) {
            break;
        }

        // Create graph
        vector<vector<ll>> v;
        v.resize(n, vector<ll>(n, inf));

        // Make all nodes reach themselves in 0 time
        for(ll i = 0; i < n; i++) {
            v[i][i] = 0;
        }

        // Add all edges
        for(ll i = 0; i < m; i++) {
            ll n1, n2, w;
            cin >> n1 >> n2 >> w;

            v[n1][n2] = min(v[n1][n2], w);
        }

        // Floyd Warshall
        for(ll k = 0; k < n; k++) {
            for(ll i = 0; i < n; i++) {
                for(ll j = 0; j < n; j++) {
                    if(v[i][k] < inf && v[k][j] < inf) {
                        v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
                    }
                }
            }
        }

        // Check negative cycles
        for(ll i = 0; i < n; i++) {
            for(ll j = 0; j < n; j++) {
                for(ll k = 0; k < n; k++) {
                    if(v[k][k] < 0 && v[i][k] != inf && v[k][j] != inf) {
                        v[i][j] = -inf;
                    }
                }
            }
        }

        // Process queries
        for(ll i = 0; i < q; i++) {
            ll n1, n2;
            cin >> n1 >> n2;

            if(v[n1][n2] == inf) {
                cout << "Impossible" << endl;
                continue;
            }

            if(v[n1][n2] == -inf) {
                cout << "-Infinity" << endl;
                continue;
            }

            cout << v[n1][n2] << endl;
        }

        cout << endl;
    }
}
