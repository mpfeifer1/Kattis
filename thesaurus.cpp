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





int find(vector<int>& d, int a) {
    if(d[a] < 0) {
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

    d[a] = max(d[a], d[b]);
    d[b] = a;
}

int size(vector<int>& d, int a) {
    a = find(d, a);
    return -d[a];
}

int main() {
    //file();
    fast();

    int n, m;
    cin >> n >> m;

    map<string, int> conv;
    vector<int> initial;
    vector<int> d;

    int unique = 0;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if(conv.count(s) == 0) {
            conv[s] = unique;
            unique++;
            d.pb(-s.length());
        }
        initial.pb(conv[s]);
    }

    for(int i = 0; i < m; i++) {
        string s1, s2;
        cin >> s1 >> s2;

        if(conv.count(s1) == 0) {
            conv[s1] = unique;
            unique++;
            d.pb(-s1.length());
        }

        if(conv.count(s2) == 0) {
            conv[s2] = unique;
            unique++;
            d.pb(-s2.length());
        }

        join(d, conv[s1], conv[s2]);
    }

    int ans = 0;
    for(auto i : initial) {
        ans += size(d, i);
    }
    cout << ans << endl;

    return 0;
}
