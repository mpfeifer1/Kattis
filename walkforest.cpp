// Michael Pfeifer
// Version 02, 2018/01/17

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

#define enld endl
#define endl '\n'
#define pb push_back
#define debug(x) cout<<#x<<" -> "<<x<<'\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define umap unordered_map;
#define uset unordered_set;

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

ll readint(){
    char r;
    bool start=false,neg=false;
    ll ret=0;
    while(true){
        r=getchar();
        if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
            continue;
        }
        if((r-'0'<0 || r-'0'>9) && r!='-' && start){
            break;
        }
        if(start)ret*=10;
        start=true;
        if(r=='-')neg=true;
        else ret+=r-'0';
    }
    if(!neg) return ret;
    else return -ret;
}





int main() {
    //file();
    //fast();

    ll n, m;
    while(cin >> n && cin >> m) {
        // Set up magic numbers
        int home = 2;
        int office = 1;

        // Build adjacency list
        vector<vector<pair<ll,ll>>> adj(n+1);
        vector<pair<ll,ll>> edges;
        for(ll i = 0; i < m; i++) {
            ll n1, n2, w;
            cin >> n1 >> n2 >> w;
            adj[n1].push_back({w,n2});
            adj[n2].push_back({w,n1});
            edges.push_back({n1,n2});
        }

        // Dijkstra's from home(1) to office(0)
        vector<ll> dist(n+1, inf);
        dist[home] = 0;
        priority_queue<pair<ll,ll>,
                       vector<pair<ll,ll>>,
                       greater<pair<ll,ll>>
                      > q;
        q.push({0,home});

        // Run Dijkstra's
        while(!q.empty()) {
            ll curr = q.top().second;
            q.pop();

            for(auto i : adj[curr]) {
                ll weight = i.first;
                ll next = i.second;
                if(dist[curr] + weight < dist[next]) {
                    dist[next] = dist[curr] + weight;
                    q.push({dist[next], next});
                }
            }
        }

        /*
        // Debugging print
        for(auto i : dist) {
            cout << i << " ";
        }
        cout << enld;
        */

        // Toposort
        vector<ll> deg(n+1, 0);
        for(auto i : edges) {
            if(dist[i.first] < dist[i.second]) {
                deg[i.first]++;
            }
            if(dist[i.second] < dist[i.first]) {
                deg[i.second]++;
            }
        }

        // Toposort to remove extras
        queue<ll> zeroin;
        for(int i = 1; i <= n; i++) {
            if(deg[i] == 0 && i != office) {
                zeroin.push(i);
            }
        }

        while(!zeroin.empty()) {
            ll curr = zeroin.front();
            zeroin.pop();

            for(auto i : adj[curr]) {
                ll next = i.second;
                if(dist[next] < dist[curr]) {
                    deg[next]--;
                    if(deg[next] == 0 && next != office) {
                        zeroin.push(next);
                    }
                }
            }
        }

        // Toposort for real
        vector<ll> ways(n+1,0);
        ways[office] = 1;
        zeroin.push(office);
        while(!zeroin.empty()) {
            ll curr = zeroin.front();
            zeroin.pop();

            for(auto i : adj[curr]) {
                ll next = i.second;
                if(dist[next] < dist[curr]) {
                    ways[next] += ways[curr];

                    deg[next]--;
                    if(deg[next] == 0) {
                        zeroin.push(next);
                    }
                }
            }
        }

        cout << ways[home] << endl;
    }

}
