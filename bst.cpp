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





int main() {
    //file();
    fast();

    int n;
    cin >> n;

    vector<int> dist(n+2, 0);

    ll total = 0;
    set<int> seen;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;

        // Find options
        seen.insert(t);
        auto it1 = seen.find(t);
        auto it2 = seen.find(t);

        // Get cost
        int cost = 0;
        if(it1 != seen.begin()) {
            it1--;
            cost = max(dist[*(it1)], cost);
        }
        if(it2 != seen.end()) {
            it2++;
            if(it2 != seen.end()) {
                cost = max(dist[*(it2)], cost);
            }
        }
        total += cost;

        // Insert
        dist[t] = cost+1;

        // Print answer
        cout << total << endl;
    }

    return 0;
}
