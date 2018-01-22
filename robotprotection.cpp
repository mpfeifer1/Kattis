// Michael Pfeifer
// Version 02, 2018/01/17

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
const ld prec = .00001;

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

ll readint(){
    char r;
    bool start=false,neg=false;
    ll ret=0;
    while(true){
        r=getchar();
        if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
            continue;
        }
        if((r-'0'<0 || r-'0'>9) && r!='-' && start){
            break;
        }
        if(start)ret*=10;
        start=true;
        if(r=='-')neg=true;
        else ret+=r-'0';
    }
    if(!neg) return ret;
    else return -ret;
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

int main() {
    //file();
    //fast();

    int n;
    while(cin >> n && n != 0) {
        vector<point> v(n);
        for(auto& i : v) {
            cin >> i.x >> i.y;
        }

        if(n <= 2) {
            cout << "0.0" << enld;
            continue;
        }

        vector<point> hull = convex(v);

        cout << fixed;
        cout.precision(1);
        cout << area(hull) << endl;
    }

}
