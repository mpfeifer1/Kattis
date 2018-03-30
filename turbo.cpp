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

    indexed_set<pair<int,int>> byidx;
    set<pair<int,int>> bynum;

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        byidx.insert({i,t});
        bynum.insert({t,i});
    }

    int cnt = 0;
    while(!bynum.empty()) {
        pair<int,int> here;

        if(cnt % 2 == 0) {
            here = *bynum.begin();
            cout << byidx.order_of_key({here.second, here.first}) << endl;
        }
        else {
            here = *prev(bynum.end());
            cout << bynum.size()-1-byidx.order_of_key({here.second, here.first}) << endl;
        }

        bynum.erase(here);
        byidx.erase({here.second, here.first});
        cnt++;
    }

    return 0;
}
