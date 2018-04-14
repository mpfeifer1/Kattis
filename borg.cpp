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





struct edge {
    pair<int,int> p1;
    pair<int,int> p2;
    int weight;
};

bool cmp(edge& e1, edge& e2) {
    return e1.weight < e2.weight;
}

int n, m;

bool inrange(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

int spot(pair<int,int>& p) {
    return p.first * m + p.second;
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

void bfs(vector<string>& v, vector<edge>& edges, pair<int,int> p) {
    vector<vector<int>> dist;
    dist.resize(n, vector<int>(m, iinf));

    queue<pair<int,int>> q;
    q.push(p);
    dist[p.first][p.second] = 0;

    vector<pair<int,int>> movement = {{1,0},{-1,0},{0,1},{0,-1}};

    // Run BFS
    while(!q.empty()) {
        int currx = q.front().first;
        int curry = q.front().second;
        q.pop();

        // If this is an alien or character, add an edge
        if(v[currx][curry] == 'S' || v[currx][curry] == 'A') {
            edge e;
            e.p1 = p;
            e.p2 = {currx,curry};
            e.weight = dist[currx][curry];
            edges.pb(e);
        }

        // Try all movement
        for(auto i : movement) {
            int nextx = currx + i.first;
            int nexty = curry + i.second;
            if(inrange(nextx,nexty)) {
                if(v[nextx][nexty] == '#') {
                    continue;
                }
                if(dist[nextx][nexty] > dist[currx][curry] + 1) {
                    dist[nextx][nexty] = dist[currx][curry] + 1;
                    q.push({nextx,nexty});
                }
            }
        }
    }

}

int solve() {
    // Read in input
    cin >> m >> n;
    cin.ignore();
    vector<string> v(n);
    for(auto& i : v) {
        getline(cin, i);
        while(i.size() < m) {
            i.pb(' ');
        }
        //cout << i << endl;
    }

    vector<pair<int,int>> points;

    // Find all endpoints
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == 'A' || v[i][j] == 'S') {
                points.pb({i,j});
            }
        }
    }

    // For each endpoint, find dist to all other endpoints, add to list
    vector<edge> edges;
    for(auto i : points) {
        // BFS, add to list
        bfs(v, edges, i);
    }

    // Run min spanning tree
    sort(all(edges), cmp);
    int total = 0;
    vector<int> d(n*m, -1);
    for(auto i : edges) {
        if(find(d, spot(i.p1)) != find(d, spot(i.p2))) {
            join(d, spot(i.p1), spot(i.p2));
            total += i.weight;
        }
    }

    return total;;
}

int main() {
    //file();
    fast();

    int cases;
    cin >> cases;
    while(cases--) {
        cout << solve() << endl;
    }

    return 0;
}
