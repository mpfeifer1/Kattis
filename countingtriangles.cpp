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





double PREC = .0001;

struct line {
    double x1, y1, x2, y2;
};

// Returns where two lines intersect
pair<double,double> intersect(line l1, line l2) {
    double a1 = l1.y2 - l1.y1;
    double b1 = l1.x1 - l1.x2;
    double c1 = a1*(l1.x1) + b1*(l1.y1);

    double a2 = l2.y2 - l2.y1;
    double b2 = l2.x1 - l2.x2;
    double c2 = a2*(l2.x1) + b2*(l2.y1);

    double determinant = a1*b2 - a2*b1;

    double x = (b2*c1 - b1*c2)/determinant;
    double y = (a1*c2 - a2*c1)/determinant;

    return {x,y};
}

bool in(double v, double b1, double b2) {
    if(b1 > b2) {
        swap(b1, b2);
    }

    return v >= b1 && v <= b2;
}

// Returns if two lines can intersect
bool canintersect(line l1, line l2) {
    double a1 = l1.y2 - l1.y1;
    double b1 = l1.x1 - l1.x2;
    double c1 = a1*(l1.x1) + b1*(l1.y1);

    double a2 = l2.y2 - l2.y1;
    double b2 = l2.x1 - l2.x2;
    double c2 = a2*(l2.x1) + b2*(l2.y1);

    double determinant = a1*b2 - a2*b1;

    double x = (b2*c1 - b1*c2)/determinant;
    double y = (a1*c2 - a2*c1)/determinant;

    if(!in(x, l1.x1, l1.x2) ||
       !in(x, l2.x1, l2.x2) ||
       !in(y, l1.y1, l1.y2) ||
       !in(y, l2.y1, l2.y2)) {
        return false;
    }

    return abs(determinant) > PREC;
}

// Returns true if two points are different
bool diff(pair<double,double> p1, pair<double,double> p2) {
    return (abs(p1.first-p2.first) > PREC) ||
           (abs(p1.second-p2.second) > PREC);
}

// Returns if three lines make a triangle
bool triangle(line l1, line l2, line l3) {
    pair<double,double> i1, i2, i3;

    if(!canintersect(l1,l2)) {
        return false;
    }
    if(!canintersect(l2,l3)) {
        return false;
    }
    if(!canintersect(l1,l3)) {
        return false;
    }

    i1 = intersect(l1,l2);
    i2 = intersect(l2,l3);
    i3 = intersect(l1,l3);

    if(diff(i1,i2) && diff(i2,i3) && diff(i3,i1)) {
        return true;
    }
    return false;
}

int main() {
    //file();
    //fast();

    int n;
    while(cin >> n && n != 0) {
        vector<line> v(n);
        for(auto& i : v) {
            cin >> i.x1 >> i.y1 >> i.x2 >> i.y2;
        }

        int total = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                for(int k = j+1; k < n; k++) {
                    bool works = triangle(v[i], v[j], v[k]);
                    if(works) {
                        total++;
                    }
                }
            }
        }

        cout << total << endl;
    }

}
