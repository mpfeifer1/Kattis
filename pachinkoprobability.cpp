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

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1].pb(n2);
    }

    queue<int> zeroin;
    vector<ll> ways(n,0);
    vector<int> deg(n,0);
    for(int i = 0; i < n; i++) {
        for(auto next : adj[i]) {
            deg[next]++;
        }
    }

    for(int i = 0; i < n; i++) {
        if(deg[i] == 0) {
            zeroin.push(i);
            ways[i] = 1;
        }
    }

    while(!zeroin.empty()) {
        int curr = zeroin.front();
        zeroin.pop();

        for(auto next : adj[curr]) {
            deg[next]--;
            ways[next] += ways[curr];
            if(deg[next] == 0) {
                zeroin.push(next);
            }
        }
    }

    int q;
    cin >> q;

    unordered_set<int> gates;
    for(int i = 0; i < q; i++) {
        int t;
        cin >> t;
        gates.insert(t);
    }

    ll totalpaths = 0;
    ll winpaths = 0;
    for(int i = 0; i < n; i++) {
        if(adj[i].size() == 0) {
            totalpaths += ways[i];
            if(gates.count(i) > 0) {
                winpaths += ways[i];
            }
        }
    }

    cout << "winning paths " << winpaths << endl;
    cout << "total paths " << totalpaths << endl;
}
