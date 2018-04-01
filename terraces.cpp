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





int n, m;

int spot(int i, int j) {
    return i*n+j;
}

int find(vector<int>& d, int a) {
    if(d[a] == -1) {
        return a;
    }
    return d[a] = find(d, d[a]);
}

void join(vector<int>& d, int a, int b) {
    a = find(d, a);
    b = find(d, b);
    if(a == b) return;
    d[a] = b;
}

int main() {
    //file();
    //fast();

    cin >> n >> m;

    vector<vector<int>> v;
    v.resize(m, vector<int>(n));

    for(auto& i : v) {
        for(auto& j : i) {
            cin >> j;
        }
    }

    vector<bool> works(n*m, true);
    vector<int> d(n*m, -1);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(i > 0) {
                if(v[i][j] == v[i-1][j]) {
                    join(d, spot(i,j), spot(i-1,j));
                }
                else if(v[i][j] < v[i-1][j]) {
                    works[spot(i-1,j)] = false;
                }
                else {
                    works[spot(i,j)] = false;
                }
            }
            if(j > 0) {
                if(v[i][j] == v[i][j-1]) {
                    join(d, spot(i,j), spot(i,j-1));
                }
                else if(v[i][j] < v[i][j-1]) {
                    works[spot(i,j-1)] = false;
                }
                else {
                    works[spot(i,j)] = false;
                }
            }
        }
    }

    for(int i = 0; i < n*m; i++) {
        int here = find(d, i);
        if(!works[i]) {
            works[here] = false;
        }
    }

    int count = 0;
    for(int i = 0; i < n*m; i++) {
        int here = find(d, i);
        if(works[here]) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
