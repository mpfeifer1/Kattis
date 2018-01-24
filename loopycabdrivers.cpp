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





void dfs1(vector<int>* adj, vector<bool>& vis, stack<int>& s, int curr) {
    vis[curr] = true;
    for(auto& i : adj[curr]) {
        if(!vis[i]) {
            dfs1(adj, vis, s, i);
        }
    }
    s.push(curr);
}

void dfs2(vector<int>* adj, vector<bool>& vis, vector<int>& comp, int curr) {
    vis[curr] = true;
    comp.pb(curr);

    for(auto& i : adj[curr]) {
        if(!vis[i]) {
            dfs2(adj, vis, comp, i);
        }
    }
}

umap<string,int> conv;
umap<int,string> rev;

bool cmp1(int& a, int& b) {
    return rev[a] < rev[b];
}

bool cmp2(vector<int>& v1, vector<int>& v2) {
    return rev[v1[0]] < rev[v2[0]];
}

struct edge {
    int n1, n2;
};

int main() {
    //file();
    fast();

    int n;
    cin >> n;

    vector<edge> edges;

    int unique = 0;
    for(int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;

        // If unseen, add
        if(!conv.count(s1)) {
            conv[s1] = unique;
            rev[unique] = s1;
            unique++;
        }
        if(!conv.count(s2)) {
            conv[s2] = unique;
            rev[unique] = s2;
            unique++;
        }

        // Get node numbers
        int n1 = conv[s1];
        int n2 = conv[s2];

        // Add to adjacency
        edges.pb({n1,n2});
    }

    // Build Adjacency
    vector<int> adj1[unique];
    vector<int> adj2[unique];
    for(auto& i : edges) {
        adj1[i.n1].pb(i.n2);
        adj2[i.n2].pb(i.n1);
    }

    // Run first DFS to get 'leave' times
    stack<int> s;
    vector<bool> vis(unique, false);
    for(int i = 0; i < unique; i++) {
        if(!vis[i]) {
            dfs1(adj1, vis, s, i);
        }
    }

    // Run second DFS to get components
    vector<int> single;
    vector<vector<int>> other;
    vis.clear();
    vis.resize(unique, false);
    while(!s.empty()) {
        int i = s.top();
        s.pop();

        if(!vis[i]) {
            vector<int> component;
            dfs2(adj2, vis, component, i);
            if(component.size() == 1) {
                single.pb(component[0]);
            }
            else {
                other.pb(component);
            }
        }
    }

    // Sort all
    for(auto& i : other) {
        sort(all(i), cmp1);
    }
    sort(all(other), cmp2);
    sort(all(single), cmp1);

    // Print connected components
    for(auto& i : other) {
        cout << "okay ";
        for(auto& j : i) {
            cout << rev[j] << " ";
        }
        cout << endl;
    }

    // Print lone components
    if(single.size() > 0) {
        cout << "avoid ";
        for(auto& i : single) {
            cout << rev[i] << " ";
        }
        cout << endl;
    }

}
