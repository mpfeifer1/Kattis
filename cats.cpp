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





struct edge {
    int n1, n2, w;
};

bool cmp(edge& e1, edge& e2) {
    return e1.w < e2.w;
}

int find(vector<int>& d, int a) {
    if(d[a] == -1) {
        return a;
    }
    return d[a] = find(d, d[a]);
}

void join(vector<int>& d, int a, int b) {
    a = find(d, a);
    b = find(d, b);

    if(a == b) {
        return;
    }

    d[a] = b;
}

int main() {
    //file();
    fast();

    int cases;
    cin >> cases;

    while(cases--) {
        int m, c;
        cin >> m >> c;

        vector<edge> v(c*(c-1)/2);
        for(auto& i : v) {
            cin >> i.n1 >> i.n2 >> i.w;
        }

        sort(all(v), cmp);

        int w = 0;
        vector<int> d(c, -1);
        for(auto i : v) {
            if(find(d,i.n1) != find(d,i.n2)) {
                join(d, i.n1, i.n2);
                w += i.w;
            }
        }

        if(m - w - c >= 0) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }

    return 0;
}
