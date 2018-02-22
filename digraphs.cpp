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





void print(string& s) {
    if(s.size()%2 == 0) {
        s.pop_back();
    }

    int n = s.size()/2 + 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << s[i+j];
        }
        cout << endl;
    }
}

bool dfs(map<char,set<char>>& adj, vector<char>& path, set<char>& vis, int curr, int start) {
    if(vis.count(curr) > 0) {
        return false;
    }
    vis.insert(curr);

    path.push_back(curr);

    for(auto next : adj[curr]) {
        if(next == start) {
            return true;
        }
        if(dfs(adj, path, vis, next, start)) {
            return true;
        }
    }

    path.pop_back();

    return false;
}

vector<char> cycle(map<char,set<char>>& adj) {
    for(char i = 'a'; i <= 'z'; i++) {
        set<char> vis;
        vector<char> path;
        if(dfs(adj, path, vis, i, i)) {
            return path;
        }
    }
    return {};
}

int main() {
    //file();
    //fast();

    int cases;
    cin >> cases;
    while(cases--) {
        // Build entire adjacency list
        map<char,set<char>> adj;
        for(char i = 'a'; i <= 'z'; i++) {
            for(char j = 'a'; j <= 'z'; j++) {
                adj[i].insert(j);
            }
        }

        // Set up list of degrees for toposort
        map<char,int> deg;
        for(int i = 'a'; i <= 'z'; i++) {
            deg[i] = 26;
        }

        // Remove things from adjacency list
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            char c1, c2;
            cin >> c1 >> c2;
            adj[c1].erase(c2);
            deg[c2]--;
        }

        /*
        for(char i = 'a'; i <= 'z'; i++) {
            cout << i << ": ";
            for(auto j : adj[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
        */

        // Find and use cycle
        vector<char> c = cycle(adj);
        if(c.size() > 0) {
            string res = "";
            for(int i = 0; i < 39; i++) {
                res.pb(c[i%c.size()]);
            }
            print(res);
            continue;
        }

        // Set up toposort
        map<char,char> parent;
        map<char,char> path;
        for(char i = 'a'; i <= 'z'; i++) {
            parent[i] = 0;
            path[i] = 1;
        }
        queue<char> zeroin;
        for(char i = 'a'; i <= 'z'; i++) {
            if(deg[i] == 0) {
                zeroin.push(i);
            }
        }

        // Run toposort
        while(!zeroin.empty()) {
            char curr = zeroin.front();
            zeroin.pop();

            for(auto next : adj[curr]) {
                if(path[next] <= path[curr] + 1) {
                    path[next] = path[curr] + 1;
                    parent[next] = curr;
                }
                deg[next]--;
                if(deg[next] == 0) {
                    zeroin.push(next);
                }
            }
        }

        // Extract answer from toposort
        char best = 'a';
        for(char i = 'b'; i <= 'z'; i++) {
            if(path[i] > path[best]) {
                best = i;
            }
        }
        string ans = "";
        while(best != 0) {
            ans.pb(best);
            best = parent[best];
        }

        // Print answer
        reverse(all(ans));
        print(ans);

    }

    return 0;
}
