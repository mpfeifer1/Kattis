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





void solve(int n, int m) {
    vector<vector<string>> v;
    v.resize(n+1, vector<string>(m+1, "Unallocated"));

    vector<string> queries;

    int q;
    cin >> q;
    while(q--) {
        string s;
        cin >> s;
        queries.pb(s);
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for(int i = a; i < c; i++) {
            for(int j = b; j < d; j++) {
                if(v[i][j] == "Unallocated") {
                    v[i][j] = s;
                }
                else {
                    v[i][j] = "Contested";
                }
            }
        }
    }

    map<string, int> ans;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            ans[v[i][j]]++;
        }
    }

    cout << "Total " << n*m << endl;
    cout << "Unallocated " << ans["Unallocated"] << endl;
    cout << "Contested " << ans["Contested"] << endl;
    for(auto i : queries) {
        cout << i << " " << ans[i] << endl;
    }
    cout << endl;
}

int main() {
    //file();
    //fast();

    int n, m;
    while(cin >> n && cin >> m) {
        solve(n, m);
    }

    return 0;
}
