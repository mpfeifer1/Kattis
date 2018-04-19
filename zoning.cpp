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

    int n;
    cin >> n;

    vector<vector<char>> v;
    vector<vector<int>> d;
    v.resize(n, vector<char>(n));
    d.resize(n, vector<int>(n,iinf));

    queue<pair<int,int>> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
            if(v[i][j] == '3') {
                d[i][j] = 0;
                q.push({i,j});
            }
        }
    }

    vector<pair<int,int>> movement = {{1,0},{-1,0},{0,1},{0,-1}};
    while(!q.empty()) {
        int currx = q.front().first;
        int curry = q.front().second;
        q.pop();

        for(auto i : movement) {
            int nextx = currx + i.first;
            int nexty = curry + i.second;

            if(nextx < n && nexty < n && nextx >= 0 && nexty >= 0) {
                if(d[nextx][nexty] > d[currx][curry] + 1) {
                    d[nextx][nexty] = d[currx][curry] + 1;
                    q.push({nextx,nexty});
                }
            }
        }
    }

    int best = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(v[i][j] == '1') {
                best = max(best, d[i][j]);
            }
        }
    }

    cout << best << endl;

    return 0;
}
