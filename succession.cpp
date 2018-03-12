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





int main() {
    //file();
    //fast();

    int n, m;
    cin >> n >> m;

    map<string, ll> blood;

    string royal;
    cin >> royal;

    map<string, set<string>> adj;
    map<string, int> degree;

    for(int i = 0; i < n; i++) {
        string c1, p1, p2;
        cin >> c1 >> p1 >> p2;

        blood[p1] = 0;
        blood[p2] = 0;
        blood[c1] = 0;

        adj[p1].insert(c1);
        adj[p2].insert(c1);

        degree[p1] += 0;
        degree[p2] += 0;
        degree[c1] += 2;
    }

    blood[royal] = (ll)1 << 55;

    queue<string> zeroin;
    for(auto i : degree) {
        if(i.second == 0) {
            zeroin.push(i.first);
        }
    }

    while(!zeroin.empty()) {
        string curr = zeroin.front();
        zeroin.pop();

        for(auto next : adj[curr]) {
            blood[next] += blood[curr] >> 1;
            degree[next]--;
            if(degree[next] == 0) {
                zeroin.push(next);
            }
        }
    }

    string best = "";
    for(int i = 0; i < m; i++) {
        string t;
        cin >> t;
        if(blood[t] > blood[best]) {
            best = t;
        }
    }

    cout << best << endl;

    return 0;
}
