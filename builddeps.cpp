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





void split(vector<string>& ans, string& s) {
    ans.pb("");
    for(auto i : s) {
        if(i == ' ') {
            ans.pb("");
        }
        else {
            ans.back().pb(i);
        }
    }
}

int main() {
    //file();
    fast();

    int n;
    cin >> n;

    vector<string> rev;
    map<string,int> cnv;
    vector<vector<int>> adj(n);

    cin.ignore();
    for(int i = 0; i < n; i++)  {
        // Take in input
        string s;
        getline(cin, s);

        // Split input
        vector<string> v;
        split(v, s);

        // Remove colon
        v[0].pop_back();

        // Add all to conversions
        for(auto i : v) {
            if(cnv.count(i) == 0) {
                cnv[i] = rev.size();
                rev.pb(i);
            }
        }

        // Convert to numbers, add to adjacency
        int n1 = cnv[v[0]];
        for(int i = 1; i < v.size(); i++) {
            adj[cnv[v[i]]].pb(n1);
        }
    }

    // Read in starting index
    string start;
    cin >> start;
    int startidx = cnv[start];

    // Count degrees
    vector<int> deg(n,0);
    for(int i = 0; i < n; i++) {
        for(auto j : adj[i]) {
            deg[j]++;
        }
    }

    // Find all zero degrees
    queue<int> zeroin;
    for(int i = 0; i < n; i++) {
        if(deg[i] == 0 && i != startidx) {
            zeroin.push(i);
        }
    }

    // Toposort away extra stuff
    while(!zeroin.empty()) {
        int curr = zeroin.front();
        zeroin.pop();

        for(auto next : adj[curr]) {
            deg[next]--;
            if(deg[next] == 0 && next != startidx) {
                zeroin.push(next);
            }
        }
    }

    // Toposort for answer
    zeroin.push(startidx);
    while(!zeroin.empty()) {
        int curr = zeroin.front();
        zeroin.pop();
        cout << rev[curr] << endl;

        for(auto next : adj[curr]) {
            deg[next]--;
            if(deg[next] == 0) {
                zeroin.push(next);
            }
        }
    }

    return 0;
}
