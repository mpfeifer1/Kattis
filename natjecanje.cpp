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

    int n, s, r;
    cin >> n >> s >> r;

    vector<bool> works(n, true);

    for(int i = 0; i < s; i++) {
        int t;
        cin >> t;
        t--;
        works[t] = false;
    }

    set<int> extra;
    for(int i = 0; i < r; i++) {
        int t;
        cin >> t;
        t--;
        extra.insert(t);
    }

    for(int i = 0; i < n; i++) {
        if(works[i]) continue;

        if(extra.count(i-1) > 0) {
            works[i] = true;
            extra.erase(i-1);
            continue;
        }
        if(extra.count(i) > 0) {
            works[i] = true;
            extra.erase(i);
            continue;
        }
        if(extra.count(i+1) > 0) {
            works[i] = true;
            extra.erase(i+1);
            continue;
        }
    }

    int bad = 0;
    for(auto i : works) {
        if(!i) {
            bad++;
        }
    }

    cout << bad << endl;

    return 0;
}
