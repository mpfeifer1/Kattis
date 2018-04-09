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

bool inrangeguys(int x, int y) {
    return x >= 0 && x <= n+1 && y >= 0 && y <= m+1;
}

bool inrangefire(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

void bfs(vector<vector<char>>& v, queue<pair<int,int>>& oldq, queue<pair<int,int>>& newq, bool fire) {
    vector<pair<int,int>> movement = {{1,0},{-1,0},{0,1},{0,-1}};
    while(!oldq.empty()) {
        int currx = oldq.front().first;
        int curry = oldq.front().second;
        oldq.pop();
        for(auto i : movement) {
            int nextx = currx + i.first;
            int nexty = curry + i.second;
            if(fire) {
                if(inrangefire(nextx,nexty)) {
                    if(v[nextx][nexty] == '.' || v[nextx][nexty] == '@') {
                        v[nextx][nexty] = '*';
                        newq.push({nextx,nexty});
                    }
                }
            }
            else {
                if(inrangeguys(nextx,nexty)) {
                    if(v[nextx][nexty] == '.') {
                        v[nextx][nexty] = '@';
                        newq.push({nextx,nexty});
                    }
                }
            }
        }
    }
}

void checkguys(vector<vector<char>>& v, queue<pair<int,int>>& guys) {
    queue<pair<int,int>> newguys;
    while(!guys.empty()) {
        pair<int,int> i = guys.front();
        guys.pop();
        if(v[i.first][i.second] != '*') {
            newguys.push(i);
        }
    }
    guys = newguys;
}

void solve() {
    cin >> m >> n;

    vector<vector<char>> v;
    v.resize(n+2, vector<char>(m+2, '.'));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }

    queue<pair<int,int>> guys;
    queue<pair<int,int>> fire;

    for(int i = 0; i < n+2; i++) {
        for(int j = 0; j < m+2; j++) {
            if(v[i][j] == '@') {
                guys.push({i,j});
            }
            if(v[i][j] == '*') {
                fire.push({i,j});
            }
        }
    }

    int time = 0;
    bool works = false;
    while(!fire.empty() || !guys.empty()) {
        queue<pair<int,int>> newguys;
        queue<pair<int,int>> newfire;

        bfs(v, guys, newguys, false);
        bfs(v, fire, newfire, true);

        for(int i = 0; i < n+2; i++) {
            if(v[i][0] == '@' || v[i][m+1] == '@') works = true;
        }
        for(int j = 0; j < m+2; j++) {
            if(v[0][j] == '@' || v[n+1][j] == '@') works = true;
        }

        checkguys(v, newguys);

        guys = newguys;
        fire = newfire;
        time++;

        if(works) break;
    }

    if(works) {
        cout << time << endl;
    }
    else {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main() {
    //file();
    //fast();

    int cases;
    cin >> cases;
    while(cases--) {
        solve();
    }

    return 0;
}
