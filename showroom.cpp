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





bool inrange(int n, int m, int nextx, int nexty) {
    return nextx >= 0 && nexty >= 0 && nextx < n && nexty < m;
}

int main() {
    //file();
    //fast();

    int n, m;
    cin >> n >> m;
    vector<vector<char>> v;
    v.resize(n, vector<char>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    vector<vector<int>> dist;
    dist.resize(n, vector<int>(m, iinf));

    int startx, starty;
    cin >> startx >> starty;
    startx--; starty--;

    dist[startx][starty] = 1;
    set<pair<int,pair<int,int>>> s;
    s.insert({0,{startx,starty}});

    vector<pair<int,int>> movement = {{1,0},{-1,0},{0,1},{0,-1}};

    while(!s.empty()) {
        int currx = (*s.begin()).second.first;
        int curry = (*s.begin()).second.second;
        s.erase(s.begin());

        for(auto i : movement) {
            int nextx = currx+i.first;
            int nexty = curry+i.second;

            if(inrange(n, m, nextx, nexty)) {
                if(v[nextx][nexty] == 'D') {
                    if(dist[nextx][nexty] > dist[currx][curry]) {
                        s.erase({dist[nextx][nexty], {nextx,nexty}});
                        dist[nextx][nexty] = dist[currx][curry];
                        s.insert({dist[nextx][nexty], {nextx,nexty}});
                    }
                }
                if(v[nextx][nexty] == 'c') {
                    if(dist[nextx][nexty] > dist[currx][curry] + 1) {
                        s.erase({dist[nextx][nexty], {nextx,nexty}});
                        dist[nextx][nexty] = dist[currx][curry] + 1;
                        s.insert({dist[nextx][nexty], {nextx,nexty}});
                    }
                }
            }
        }
    }

    int best = iinf;
    for(int i = 0; i < n; i++) {
        best = min(best, dist[i][0]);
        best = min(best, dist[i][m-1]);
    }
    for(int j = 0; j < m; j++) {
        best = min(best, dist[0][j]);
        best = min(best, dist[n-1][j]);
    }

    cout << best << endl;

    return 0;
}
