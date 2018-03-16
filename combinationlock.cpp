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





int clockwise(int n1, int n2) {
    n1 += 40;
    n1 -= n2;
    n1 %= 40;
    return n1;
}

int counter(int n1, int n2) {
    n2 += 40;
    n2 -= n1;
    n2 %= 40;
    return n2;
}

int main() {
    //file();
    //fast();

    int i, n1, n2, n3;
    while(cin >> i >> n1 >> n2 >> n3) {
        if(i == 0 && n1 == 0 && n2 == 0 && n3 == 0) {
            break;
        }

        int ans = 120;

        ans += clockwise(i, n1);
        ans += counter(n1, n2);
        ans += clockwise(n2, n3);

        cout << ans*9 << endl;
    }

    return 0;
}
