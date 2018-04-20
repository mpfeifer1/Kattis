// Michael Pfeifer
// Version 04, 2018/02/17

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize ("Ofast")

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





const int MAXN = 1001;
int n, m;

char          v[MAXN][MAXN];
int           print[MAXN][MAXN];
pair<int,int> prevarr[MAXN][MAXN];
vector<pair<int,int>> adj[MAXN][MAXN];

void save() {
    // Save everywhere you can go
    for(int i = 1; i < n-1; i++) {
        for(int j = 1; j < m-1; j++) {
            if(v[i][j] != '#') {
                pair<int,int> here = prevarr[i][j];
                if(here.first != i || here.second != j) {
                    adj[here.first][here.second].pb({i,j});
                }
            }
        }
    }
}

int main() {
    //file();
    fast();

    // Read in size
    cin >> m >> n;

    // Read in board
    int startx = 0;
    int starty = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> v[i][j];

            if(v[i][j] == 'M') {
                v[i][j] = '.';
                startx = i;
                starty = j;
            }
        }
    }

    // Find where you can get to by sliding up
    for(int i = 1; i < n-1; i++) {
        for(int j = 1; j < m-1; j++) {
            if(v[i-1][j] == '#') {
                prevarr[i][j] = {i,j};
            }
            if(v[i-1][j] == '.') {
                prevarr[i][j] = {i-1,j};
            }
            if(v[i-1][j] == '_') {
                prevarr[i][j] = prevarr[i-1][j];
            }
        }
    }
    save();

    // Find where you can get to by sliding down
    for(int i = n-2; i >= 1; i--) {
        for(int j = 1; j < m-1; j++) {
            if(v[i+1][j] == '#') {
                prevarr[i][j] = {i,j};
            }
            if(v[i+1][j] == '.') {
                prevarr[i][j] = {i+1,j};
            }
            if(v[i+1][j] == '_') {
                prevarr[i][j] = prevarr[i+1][j];
            }
        }
    }
    save();

    // Find where you can get to by sliding right
    for(int i = 1; i < n-1; i++) {
        for(int j = m-2; j >= 1; j--) {
            if(v[i][j+1] == '#') {
                prevarr[i][j] = {i,j};
            }
            if(v[i][j+1] == '.') {
                prevarr[i][j] = {i,j+1};
            }
            if(v[i][j+1] == '_') {
                prevarr[i][j] = prevarr[i][j+1];
            }
        }
    }
    save();

    // Find where you can get to by sliding left
    for(int i = 1; i < n-1; i++) {
        for(int j = 1; j < m-1; j++) {
            if(v[i][j-1] == '#') {
                prevarr[i][j] = {i,j};
            }
            if(v[i][j-1] == '.') {
                prevarr[i][j] = {i,j-1};
            }
            if(v[i][j-1] == '_') {
                prevarr[i][j] = prevarr[i][j-1];
            }
        }
    }
    save();

    // Run BFS
    map<pair<int,int>, int> dist;
    dist[{startx,starty}] = 0;
    queue<pair<int,int>> q;
    q.push({startx,starty});

    while(!q.empty()) {
        pair<int,int> curr = q.front();
        q.pop();

        for(auto& next : adj[curr.first][curr.second]) {
            if(dist.count(next) == 0) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }

    // Build output
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            print[i][j] = -1;
        }
    }
    for(auto& i : dist) {
        print[i.first.first][i.first.second] = i.second;
    }

    // Print
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << print[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
