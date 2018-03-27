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

bool inrange(int x, int y) {
    return (x >= 0) && (y >= 0) && (x < n) && (y < m);
}

int main() {
    //file();
    //fast();

    cin >> n >> m;

    vector<vector<char>> v;
    v.resize(n, vector<char>(m));

    for(auto& i : v) {
        for(auto& j : i) {
            cin >> j;
        }
    }

    string s;
    cin >> s;
    s += "*";

    vector<vector<vector<int>>> vis;
    vis.resize(n, vector<vector<int>>(m, vector<int>(s.size()+1, iinf)));

    queue<tuple<int,int,int>> q;
    vis[0][0][0] = 0;
    q.push({0,0,0});

    int dist = iinf;
    while(!q.empty()) {
        int x, y, l;
        tie(x,y,l) = q.front();
        q.pop();

        if(l == s.length()) {
            dist = vis[x][y][l];
            break;
        }

        if(v[x][y] == s[l]) {
            if(vis[x][y][l+1] > vis[x][y][l] + 1) {
                vis[x][y][l+1] = vis[x][y][l] + 1;
                q.push({x,y,l+1});
            }
        }

        int nextx, nexty;

        nextx = x;
        while(true) {
            nextx--;
            if(nextx < 0) {
                break;
            }

            if(v[x][y] != v[nextx][y]) {
                if(vis[nextx][y][l] > vis[x][y][l] + 1) {
                    vis[nextx][y][l] = vis[x][y][l] + 1;
                    q.push({nextx, y, l});
                }
                break;
            }
        }

        nextx = x;
        while(true) {
            nextx++;
            if(nextx >= n) {
                break;
            }

            if(v[x][y] != v[nextx][y]) {
                if(vis[nextx][y][l] > vis[x][y][l] + 1) {
                    vis[nextx][y][l] = vis[x][y][l] + 1;
                    q.push({nextx, y, l});
                }
                break;
            }
        }

        nexty = y;
        while(true) {
            nexty--;
            if(nexty < 0) {
                break;
            }

            if(v[x][y] != v[x][nexty]) {
                if(vis[x][nexty][l] > vis[x][y][l] + 1) {
                    vis[x][nexty][l] = vis[x][y][l] + 1;
                    q.push({x, nexty, l});
                }
                break;
            }
        }

        nexty = y;
        while(true) {
            nexty++;
            if(nexty >= m) {
                break;
            }

            if(v[x][y] != v[x][nexty]) {
                if(vis[x][nexty][l] > vis[x][y][l] + 1) {
                    vis[x][nexty][l] = vis[x][y][l] + 1;
                    q.push({x, nexty, l});
                }
                break;
            }
        }
    }

    cout << dist << endl;

    return 0;
}
