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





struct point {
    int x,y;
};

bool cmp(point& p1, point& p2) {
    if(p1.x == p2.x) {
        return p1.y < p2.y;
    }
    return p1.x < p2.x;
}

bool line(point& p1, point& p2, point& p3) {
    vector<point> v = {p1,p2,p3};
    sort(all(v), cmp);

    int xdiff1 = v[1].x-v[0].x;
    int ydiff1 = v[1].y-v[0].y;
    int xdiff2 = v[2].x-v[1].x;
    int ydiff2 = v[2].y-v[1].y;

    int gcd1 = __gcd(xdiff1,ydiff1);
    xdiff1 /= gcd1;
    ydiff1 /= gcd1;

    int gcd2 = __gcd(xdiff2,ydiff2);
    xdiff2 /= gcd2;
    ydiff2 /= gcd2;

    return xdiff1 == xdiff2 && ydiff1 == ydiff2;
}

int main() {
    //file();
    //fast();

    vector<point> v;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if(c != '.') {
                v.pb({i,j});
            }
        }
    }

    n = v.size();
    int total = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            for(int k = j+1; k < n; k++) {
                if(line(v[i], v[j], v[k])) {
                    total++;
                }
            }
        }
    }

    cout << total << endl;

    return 0;
}
