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





const int COLINEAR = 0;
const int CW = 1;
const int CCW = 2;

const int INSIDE = 0;
const int OUTSIDE = 1;
const int ONEDGE = 2;

struct point {
    ld x, y;
    ld angle;
};

bool cmp(point& p1, point& p2) {
    return p1.angle < p2.angle;
}

ld getangle(ld x1, ld y1, ld x2, ld y2) {
    ld delta_x = x2 - x1;
    ld delta_y = y2 - y1;
    ld radians = atan2(delta_y, delta_x);
    return radians;
}

int main() {
    //file();
    fast();

    int n;
    cin >> n;
    deque<point> v;

    ld totalx = 0;
    ld totaly = 0;
    for(int i = 0; i < n; i++) {
        ld x, y;
        char c;
        cin >> x >> y >> c;
        if(c == 'Y') {
            v.pb({x,y});
            totalx += x;
            totaly += y;
        }
    }

    ld avgx = totalx / v.size();
    ld avgy = totaly / v.size();

    for(auto& i : v) {
        i.angle = getangle(avgx, avgy, i.x, i.y);
    }
    sort(all(v), cmp);

    int sz = v.size()-1;
    while(v[0].x > v[sz].x || (v[0].x == v[sz].x && v[0].y > v[sz].y)) {
        v.push_front(v.back());
        v.pop_back();
    }

    while(v[0].x > v[1].x || (v[0].x == v[1].x && v[0].y > v[1].y)) {
        v.pb(v.front());
        v.pop_front();
    }

    cout << v.size() << endl;
    for(auto& i : v) {
        cout << (int)i.x << " " << (int)i.y << endl;
    }

    return 0;
}
