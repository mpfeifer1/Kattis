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





deque<deque<int>> generate(int n) {
    if(n == 1) {
        return {{1}};
    }
    if(n == 2) {
        return {{1,2},{2,1}};
    }

    deque<deque<int>> old = generate(n-1);

    deque<deque<int>> ans;
    for(int i = 0; i < old.size(); i++) {
        if(i%2==0) {
            old[i].pb(n);
            ans.pb(old[i]);
            for(int j = old[i].size()-2; j >= 0; j--) {
                swap(old[i][j], old[i][j+1]);
                ans.pb(old[i]);
            }
        }
        else {
            old[i].push_front(n);
            ans.pb(old[i]);
            for(int j = 0; j < old[i].size()-1; j++) {
                swap(old[i][j], old[i][j+1]);
                ans.pb(old[i]);
            }
        }
    }
    return ans;
}

int main() {
    //file();
    fast();

    int n;
    cin >> n;

    for(auto i : generate(n)) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
