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





vector<string> split(string& s) {
    vector<string> v = {""};
    for(auto& i : s) {
        if(i == ' ') {
            v.pb("");
        }
        else {
            v.back().pb(i);
        }
    }
    return v;
}

int main() {
    //file();
    //fast();

    int n;
    cin >> n;
    map<string, set<string>> adj;

    cin.ignore();
    for(int i = 0; i < n; i++) {
        string s;
        getline(cin, s);

        vector<string> v = split(s);
        for(int i = 1; i < v.size(); i++) {
            adj[v[0]].insert(v[i]);
            adj[v[i]].insert(v[0]);
        }
    }

    string start, end;
    cin >> start >> end;

    map<string, string> prev;
    prev[start] = "thisisthestart";

    queue<string> q;
    q.push(start);
    while(!q.empty()) {
        string curr = q.front();
        q.pop();

        for(auto next : adj[curr]) {
            if(prev.count(next) == 0) {
                prev[next] = curr;
                q.push(next);
            }
        }
    }

    if(prev.count(end) == 0) {
        cout << "no route found" << endl;
        return 0;
    }

    vector<string> ans;
    string curr = end;
    while(curr != "thisisthestart") {
        ans.pb(curr);
        curr = prev[curr];
    }
    reverse(all(ans));

    for(auto i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
