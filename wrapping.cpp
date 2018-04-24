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
    ld x, y;
    point(ld xloc, ld yloc) : x(xloc), y(yloc) {}
    point() {}
    point& operator= (const point& other) {
        x = other.x, y = other.y;
        return *this;
    }
    int operator== (const point& other) const {
        return abs(other.x - x) < prec && abs(other.y - y) < prec;
    }
    bool operator< (const point& other) const {
        return (x < other.x ? true : (abs(other.x - x) < prec && y < other.y));
    }
};

struct vect {
    ld i, j;
};

ld crossproduct(point a, point b, point c) {
    vect ab, ac;
    ab.i = b.x - a.x;
    ab.j = b.y - a.y;
    ac.i = c.x - a.x;
    ac.j = c.y - a.y;
    return (ab.i * ac.j - ab.j * ac.i);
}

ld pointsquareddist(point a, point b) {
    return pow(a.x-b.x, 2) + pow(a.y-b.y,2);
}

ld area(vector<point> v) {
    ld total = 0;
    int n = v.size();
    for(int i=0, j=1; i < n; i++, j=(i+1)%n) {
        total += (v[i].x * v[j].y) - (v[i].y * v[j].x);
    }
    return abs(total) / 2;
}

vector<point> convex(vector<point> x) {
    vector<point> hull;
    ll size = x.size();
    vector<bool> used(size, false);

    int p = 0;
    for(int i = 1; i < size; i++) {
        if(x[i].x < x[p].x) {
            p = i;
        }
    }
    int start = p;

    do {
        int n = -1;
        ld dist = 0;

        for(int i = 0; i < size; i++) {
            if(i == p || used[i]) {
                continue;
            }
            if(n == -1) {
                n = i;
            }
            ld cross = crossproduct(x[p], x[i], x[n]);
            ld d = pointsquareddist(x[i], x[p]);

            if(cross < 0 || (abs(cross) < prec && d > dist)) {
                n = i;
                dist = d;
            }
        }

        p = n;
        used[p] = true;
        hull.pb(x[p]);
    } while(start != p);

    return hull;
}

point rotate(point p, point c, ld angle) {
    ld x = p.x - c.x;
    ld y = p.y - c.y;
    ld hyp = sqrt(pow(x,2)+pow(y,2));

    ld oldangle = atan2(y,x);
    angle = -angle + oldangle;

    ld newx = hyp * cos(angle);
    ld newy = hyp * sin(angle);

    return {c.x+newx,c.y+newy};
}


void solve() {
    int n;
    cin >> n;

    ld usedarea = 0;
    ld totalarea = 0;

    vector<point> all;

    for(int i = 0; i < n; i++) {
        ld x, y, w, h, v;
        cin >> x >> y >> w >> h >> v;
        v /= 180.0 / M_PI;

        usedarea += w * h;

        w /= 2;
        h /= 2;

        point c(x,y);
        point p1(x+w,y+h);
        point p2(x+w,y-h);
        point p3(x-w,y+h);
        point p4(x-w,y-h);

        p1 = rotate(p1, c, v);
        p2 = rotate(p2, c, v);
        p3 = rotate(p3, c, v);
        p4 = rotate(p4, c, v);

        all.pb(p1);
        all.pb(p2);
        all.pb(p3);
        all.pb(p4);
    }

    vector<point> hull = convex(all);
    totalarea = abs(area(hull));

    ld ans = (usedarea / totalarea) * 100.0;
    ll print = ll((ans*10) + .50001);

    cout << fixed;
    cout.precision(1);
    cout << ld(print)/10 << " %" << endl;
}

int main() {
    //file();
    //fast();

    int cases;
    cin >> cases;
    while(cases--) {
        solve();
    }

    return 0;
}
