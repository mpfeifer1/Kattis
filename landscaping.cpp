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
const ll  inf  = 1e18 + iinf + 10;
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





int n;
const int MAXN = 50*50*2;
int cap[MAXN][MAXN];
int nedge[MAXN];
int edge[MAXN][MAXN];
int prev[MAXN];

void addedge(int a, int b, int c) {
    edge[a][nedge[a]++] = b;
    cap[a][b] = c;
}

int maxFlowDinic(int s, int t) {
    int q[MAXN];
    int prev[MAXN];
    int flow = 0;
    int qf, qb, bot, u, v;

    while (true) {
        qf = qb = 0;
        memset(prev, -1, sizeof(prev));

        q[qb++] = s;
        prev[s] = -2;

        while (qb > qf && prev[t] == -1) {
            u = q[qf++];
            for (int i = 0; i < nedge[u]; i++)
                if (prev[v = edge[u][i]] == -1 && cap[u][v])
                    prev[q[qb++] = v] = u;
        }

        if (prev[t] == -1) return flow;

        for (int z = 0; z < n; z++)
            if (cap[z][t] && prev[z] != -1) {
                bot = cap[z][t];

                for (v = z, u = prev[v]; u >= 0; v = u, u = prev[v])
                    bot = min(bot , cap[u][v]);

                if (!bot) continue;
                cap[z][t] -= bot;
                cap[t][z] += bot;

                for (v = z, u = prev[v]; u >= 0; v = u, u = prev[v])
                    cap[u][v] -= bot , cap[v][u] += bot;
                flow += bot;
            }
    }
}

int main() {
    //file();
    //fast();

    ll n, m, a, b;
    cin >> n >> m >> a >> b;

    int extra = __gcd(a,b);
    a /= extra;
    b /= extra;

    vector<vector<char>> field(n, vector<char>(m));
    for(auto& i : field) {
        for(auto& j : i) {
            cin >> j;
        }
    }

    int s = n*m;
    int t = n*m + 1;

    ::n = n*m+2;

    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            int curr = (i*m)+j;
            if(i > 0) {
                // join
                int prev = ((i-1)*m)+j;
                addedge(curr,prev,a);
                addedge(prev,curr,a);
            }
            if(j > 0) {
                // join
                int prev = (i*m)+j-1;
                addedge(curr,prev,a);
                addedge(prev,curr,a);
            }
            if(field[i][j] == '#') {
                // source
                addedge(s,curr,b);
            }
            else {
                // sink
                addedge(curr,t,b);
            }
        }
    }

    cout << maxFlowDinic(s,t) * (ll)extra << endl;
}


