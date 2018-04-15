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
    return nextx >= 0 && nextx < n && nexty >= 0 && nexty < m;
}

int main() {
    //file();
    //fast();

    int n, m;
    cin >> n >> m;

    vector<vector<char>> v;
    v.resize(n, vector<char>(m));

    cin.ignore();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            v[i][j] = getchar();
        }
        cin.ignore();
    }

    vector<vector<int>> risk;
    risk.resize(n, vector<int>(m,0));

    vector<pair<int,int>> movement = {{1,0},{-1,0},{0,-1},{0,1}};

    int startx = 0;
    int starty = 0;
    int endx = 0;
    int endy = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == ' ') {
                for(auto k : movement) {
                    if(v[i+k.first][j+k.second] == ' ') {
                        risk[i][j]++;
                    }
                }
            }
            if(v[i][j] == 'E') {
                startx = i;
                starty = j;
            }
            if(v[i][j] == 'D') {
                endx = i;
                endy = j;
            }
            if(v[i][j] == '#') {
                risk[i][j] = -1;
            }
        }
    }

    vector<vector<int>> dist;
    dist.resize(n, vector<int>(m,iinf));
    dist[startx][starty] = 0;

    set<pair<int,pair<int,int>>> q;
    q.insert({0,{startx,starty}});

    while(!q.empty()) {
        int currx = (*q.begin()).second.first;
        int curry = (*q.begin()).second.second;
        q.erase(q.begin());

        for(auto i : movement) {
            int nextx = currx + i.first;
            int nexty = curry + i.second;

            if(!inrange(n, m, nextx, nexty)) {
                continue;
            }

            if(risk[nextx][nexty] != -1) {
                if(dist[nextx][nexty] > dist[currx][curry] + risk[nextx][nexty]) {
                    q.erase({dist[nextx][nexty], {nextx, nexty}});
                    dist[nextx][nexty] = dist[currx][curry] + risk[nextx][nexty];
                    q.insert({dist[nextx][nexty], {nextx, nexty}});
                }
            }
        }
    }

    int totalrisk = dist[endx][endy];
    int total = 0;
    for(auto i : risk) {
        for(auto j : i) {
            if(j > 0) {
                total += j;
            }
        }
    }


    cout << fixed;
    cout.precision(8);

    if(total == 0) {
        cout << 0 << endl;
    }
    else {
        cout << ld(totalrisk) / ld(total) << endl;
    }

    return 0;
}
