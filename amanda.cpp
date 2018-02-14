// Michael Pfeifer
// Version 03, 2018/01/30

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





bool impossible = false;

pair<int,int> dfs2(vector<vector<int>>& adj, vector<char>& state, vector<bool>& vis, int curr) {
    if(vis[curr]) {
        return {0,0};
    }
    vis[curr] = true;

    int reds = 0;
    int blues = 0;

    if(state[curr] == 'r') {
        reds++;
    }
    else {
        blues++;
    }

    for(auto next : adj[curr]) {
        if(state[next] == 'r' && state[curr] == 'r') {
            impossible = true;
        }
        else if(state[next] == 'b' && state[curr] == 'b') {
            impossible = true;
        }
        else {
            if(state[curr] == 'r') {
                state[next] = 'b';
            }
            else {
                state[next] = 'r';
            }

            pair<int,int> p = dfs2(adj, state, vis, next);
            reds += p.first;
            blues += p.second;
        }
    }

    return {reds, blues};
}

int dfs1(vector<vector<int>>& adj, vector<char>& state, vector<bool>& vis, int curr) {
    if(vis[curr]) {
        return 0;
    }
    vis[curr] = true;

    int count = 0;
    if(state[curr] == '1') {
        count++;
    }

    for(auto next : adj[curr]) {
        if(state[next] == '1' && state[curr] == '1') {
            impossible = true;
        }
        else if(state[next] == '0' && state[curr] == '0') {
            impossible = true;
        }
        else {
            if(state[curr] == '0') {
                state[next] = '1';
            }
            else {
                state[next] = '0';
            }

            count += dfs1(adj, state, vis, next);
        }
    }

    return count;
}

struct edge {
    int n1, n2, count;
};

int main() {
    //file();
    fast();

    int n, m;
    cin >> n >> m;

    vector<char> state(n, '?');

    vector<vector<int>> adj(n);

    vector<edge> zero;
    vector<edge> one;
    vector<edge> two;

    for(int i = 0; i < m; i++) {
        edge e;
        cin >> e.n1 >> e.n2 >> e.count;
        e.n1--; e.n2--;

        if(e.count == 0) {
            zero.pb(e);
        }
        if(e.count == 1) {
            one.pb(e);
            adj[e.n1].pb(e.n2);
            adj[e.n2].pb(e.n1);
        }
        if(e.count == 2) {
            two.pb(e);
        }
    }

    // Add all 'zero' edges
    for(auto i : zero) {
        state[i.n1] = '0';
        state[i.n2] = '0';
    }

    // Add all 'two' edges, checking if possible
    for(auto i : two) {
        if(state[i.n1] == '0' || state[i.n2] == '0') {
            impossible = true;
        }
        state[i.n1] = '1';
        state[i.n2] = '1';
    }

    // For each existing component, DFS to see if possible
    int ans = 0;
    vector<bool> vis(n, false);
    for(int i = 0; i < n; i++) {
        if(!vis[i] && (state[i] == '1' || state[i] == '0')) {
            // DFS, count '1's, check possible
            ans += dfs1(adj, state, vis, i);
        }
    }

    for(int i = 0; i < n; i++) {
        if(!vis[i] && state[i] == '?') {
            // DFS, count 'r' and 'b', print min
            state[i] = 'r';
            pair<int,int> p = dfs2(adj, state, vis, i);
            ans += min(p.first, p.second);
        }
    }

    // Print answer
    if(impossible) {
        cout << "impossible" << endl;
    }
    else {
        cout << ans << endl;
    }

    return 0;
}
