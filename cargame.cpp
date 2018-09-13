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





struct graph {
    vector<vector<int>> adj;
    string s;
};

bool find(vector<vector<int>>& g, string& s) {
    int pos = 0;
    for(auto i : s) {
        if(g[pos][i-'a'] == iinf) {
            return false;
        }
        pos = g[pos][i-'a'];
    }
    return true;
}

int main() {
    //file();
    fast();

    int n, m;
    cin >> n >> m;

    vector<graph> v;

    for(int i = 0; i < n; i++) {
        graph g;
        cin >> g.s;

        // Build the graph for each string
        g.adj.resize(g.s.size()+1, vector<int>(26, iinf));

        // Create a node to each start
        for(int j = 0; j < g.s.size(); j++) {
            g.adj[0][g.s[j]-'a'] = min(g.adj[0][g.s[j]-'a'], j+1);
        }

        for(int j = 0; j < g.s.size(); j++) {
            for(int k = j+1; k < g.s.size(); k++) {
                // edge from i+1 to j+1
                g.adj[j+1][g.s[k]-'a'] = min(g.adj[j+1][g.s[k]-'a'], k+1);
            }
        }

        v.pb(g);
    }

    for(int i = 0; i < m; i++) {
        string s;
        cin >> s;
        for(auto& j : s) j = tolower(j);

        bool printed = false;
        for(auto& g : v) {
            if(find(g.adj, s)) {
                printed = true;
                cout << g.s << endl;
                break;
            }
        }

        if(!printed) {
            cout << "No valid word" << endl;
        }
    }

    return 0;
}
