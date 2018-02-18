// Michael Pfeifer
// Version 03, 2018/01/17

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
    fast();

    int n;
    while(cin >> n && n != 0) {
        vector<int> count(n, 0);
        vector<vector<int>> adj(n);
        vector<int> deg(n,0);

        // Read in input
        for(int i = 0; i < n; i++) {
            int n1; cin >> n1; n1--;
            int ct; cin >> ct;
            count[n1] = ct;

            int j;
            cin >> j;
            for(int k = 0; k < j; k++) {
                int n2; cin >> n2; n2--;
                adj[n2].pb(n1);
                deg[n1]++;
            }
        }

        // Find all with indegree zero
        queue<int> zeroin;
        for(int i = 0; i < n; i++) {
            if(deg[i] == 0) {
                zeroin.push(i);
            }
        }

        // Calculate answer
        int moves = 0;
        while(!zeroin.empty()) {
            int curr = zeroin.front();
            zeroin.pop();

            if(adj[curr].size() > 0) {
                int next = adj[curr][0];
                deg[next]--;
                if(deg[next] == 0) {
                    zeroin.push(next);
                }

                int diff = count[curr] - 1;
                count[next] += diff;
                moves += abs(diff);
            }
        }

        cout << moves << endl;
    }

    return 0;
}
