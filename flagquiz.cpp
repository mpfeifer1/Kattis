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





void split(vector<string>& v, string& s) {
    v.pb("");
    for(auto i : s) {
        if(i == ',') {
            v.pb("");
        }
        else {
            v.back().pb(i);
        }
    }
    /*
    for(auto i : v) {
        cout << i << '\t';
        if(i.size() < 8) {
            cout << '\t';
        }
        if(i.size() < 4) {
            cout << '\t';
        }
    }
    cout << endl;
    */
}

int getcost(vector<string>& v1, vector<string>& v2) {
    int c = 0;
    for(int i = 0; i < v1.size(); i++) {
        if(v1[i] != v2[i]) {
            c++;
        }
    }
    return c;
}

int main() {
    //file();
    //fast();

    string s;
    getline(cin,s);

    // Read in input, split it apart
    int n;
    cin >> n;
    cin.ignore();
    vector<vector<string>> v;
    vector<string> actual;
    for(int i = 0; i < n; i++) {
        getline(cin,s);
        actual.pb(s);
        v.pb({});
        split(v.back(),s);
    }

    // Calculate each line's cost
    vector<int> cost(n,0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int c = getcost(v[i], v[j]);
            cost[i] = max(cost[i],c);
        }
    }

    // Find minimum cost
    int mincost = iinf;
    for(int i = 0; i < n; i++) {
        mincost = min(cost[i], mincost);
    }

    // If minimum cost, print
    for(int i = 0; i < n; i++) {
        if(cost[i] == mincost) {
            cout << actual[i] << endl;
        }
    }

    return 0;
}
