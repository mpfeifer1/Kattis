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





struct cmp1 {
    bool operator() (const pair<int,int>& lhs, const pair<int,int>& rhs) const {
        return lhs.second < rhs.second;
    }
};

int main() {
    //file();
    fast();

    int cases;
    cin >> cases;
    while(cases--) {
        int n, m;
        cin >> n >> m;

        set<pair<int,int>, cmp1> s;
        indexed_set<pair<int,int>> is;

        for(int i = 1; i <= n; i++) {
            pair<int,int> d = {i,i};
            s.insert(d);
            is.insert(d);
        }

        for(int i = 0; i < m; i++) {
            int q;
            cin >> q;

            pair<int,int> d = *s.find({0,q});
            cout << is.order_of_key(d) << " ";

            s.erase(d);
            is.erase(d);

            d.first = -i;

            s.insert(d);
            is.insert(d);
        }
        cout << endl;
    }

    return 0;
}
