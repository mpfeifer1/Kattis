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
    int x, y, idx;
};

struct edge {
    int n1, n2, w;
};

bool cmp(edge& e1, edge& e2) {
    return e1.w < e2.w;
}

int dist(point p1, point p2) {
    return abs(p1.x-p2.x) + abs(p1.y-p2.y);
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

    if(a == b) {
        return;
    }

    d[a] = b;
}

int main() {
    //file();
    fast();

    int n;
    cin >> n;

    vector<vector<int>> grid;
    grid.resize(1000, vector<int>(1000, -1));

    vector<point> v(n);
    queue<point> q;
    int idx = 0;
    for(auto& i : v) {
        cin >> i.x >> i.y;
        i.idx = idx++;
        if(grid[i.x][i.y] == -1) {
            grid[i.x][i.y] = i.idx;
            q.push({i.x, i.y, i.idx});
        }
    }

    vector<pair<int,int>> near = {{0,1},{1,0},{-1,0},{0,-1}};

    while(!q.empty()) {
        int currx = q.front().x;
        int curry = q.front().y;
        int curri = q.front().idx;
        q.pop();

        for(auto i : near) {
            int nextx = currx + i.first;
            int nexty = curry + i.second;

            if(nextx >= 0 && nexty >= 0 && nextx < 1000 && nexty < 1000) {
                if(grid[nextx][nexty] == -1) {
                    grid[nextx][nexty] = curri;
                    q.push({nextx, nexty, curri});
                }
            }
        }
    }

    set<pair<int,int>> e;
    for(int i = 1; i < 1000; i++) {
        for(int j = 0; j < 1000; j++) {
            if(grid[i][j] != grid[i-1][j]) {
                e.insert({grid[i][j], grid[i-1][j]});
            }
            if(grid[j][i] != grid[j][i-1]) {
                e.insert({grid[j][i], grid[j][i-1]});
            }
        }
    }

    vector<edge> edges;
    for(auto i : e) {
        edges.push_back({i.first, i.second, dist(v[i.first], v[i.second])});
    }
    sort(all(edges), cmp);

    vector<int> d(n, -1);
    ll ans = 0;
    for(auto i : edges) {
        if(find(d, i.n1) != find(d, i.n2)) {
            join(d, i.n1, i.n2);
            ans += i.w;
        }
    }

    cout << ans << endl;

    return 0;
}

