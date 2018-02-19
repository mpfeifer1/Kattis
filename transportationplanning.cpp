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





struct point {
    int x, y;
};

int n;
vector<point> p;
vector<vector<ld>> dist;

ld getdist(point& p1, point& p2) {
    return sqrt(pow(p1.x-p2.x,2) + pow(p1.y-p2.y,2));
}

ld sum(vector<vector<ld>> v, int n1, int n2) {
    v[n1][n2] = dist[n1][n2];
    v[n2][n1] = dist[n2][n1];

    // Floyd Warshall
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            v[i][j] = min(v[i][j], v[i][n1] + v[n1][n2] + v[n2][j]);
            v[i][j] = min(v[i][j], v[i][n2] + v[n2][n1] + v[n1][j]);
        }
    }

    // Calculate sum
    ld sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            sum += v[i][j];
        }
    }

    return sum;
}

int main() {
    //file();
    fast();

    while(cin >> n && n != 0) {
        p.clear();
        p.resize(n);
        for(auto& i : p) {
            cin >> i.x >> i.y;
        }

        dist.clear();
        dist.resize(n, vector<ld>(n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dist[i][j] = getdist(p[i],p[j]);
            }
        }

        // Create graph
        vector<vector<ld>> v;
        v.resize(n, vector<ld>(n, inf));

        // Make all nodes reach themselves in 0 time
        for(int i = 0; i < n; i++) {
            v[i][i] = 0;
        }

        // Add all edges
        int m; cin >> m;
        for(int i = 0; i < m; i++) {
            int n1, n2;
            cin >> n1 >> n2;

            v[n1][n2] = dist[n1][n2];
            v[n2][n1] = v[n1][n2];
        }

        // Floyd Warshall
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
                    v[j][i] = v[i][j];
                }
            }
        }

        // Calculate sum
        ld oldsum = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                oldsum += v[i][j];
            }
        }

        // For each pair, if better, add
        int besti = 0;
        int bestj = 0;
        ld newsum = inf;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ld sumhere = sum(v,i,j);
                if(newsum - sumhere > prec) {
                    newsum = sumhere;
                    besti = i;
                    bestj = j;
                }
            }
        }

        cout << fixed;
        cout.precision(8);
        if(abs(oldsum - newsum) < prec) {
            cout << "no addition reduces " << oldsum << endl;
        }
        else {
            cout << "adding " << besti << " " << bestj << " reduces ";
            cout << oldsum << " to " << newsum << endl;
        }

    }

    return 0;
}

