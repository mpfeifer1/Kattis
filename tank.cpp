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
#define umap unordered_map;
#define uset unordered_set;

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





struct coord {
    double x;
    double y;
};

double area(deque<coord>& v) {
    int n = v.size();
    double total = 0;
    for(int i=0, j=1; i < n; i++, j=(i+1)%n) {
        total += (v[i].x * v[j].y) - (v[i].y * v[j].x);
    }
    return abs(total) / 2;
}

coord scalepoint(coord lo, coord hi, double level) {
    double scalefactor = (level - lo.y) / (hi.y - lo.y);
    return {scalefactor * (hi.x - lo.x) + lo.x, level};
}

bool calc(deque<coord> v, double level, double target) {
    deque<coord> before;
    deque<coord> above;
    deque<coord> after;

    // Split up based on level
    bool mid = false;
    for(auto i : v) {
        if(i.y > level) {
            mid = true;
            above.push_back(i);
        }
        else {
            if(!mid) {
                before.push_back(i);
            }
            else {
                after.push_back(i);
            }
        }
    }

    // Error checking - but if it gets here, something's probably already wrong
    if(before.size() == 0 || after.size() == 0) {
        return false;
    }

    // Replace first and last in 'above' with correlating points
    coord left, right;
    left = scalepoint(after.front(), above.back(), level);
    right = scalepoint(before.back(), above.front(), level);

    // Build list of real points
    deque<coord> out;
    for(int i = 0; i < before.size(); i++) {
        out.pb(before[i]);
    }
    out.pb(right);
    out.pb(left);
    for(int i = 0; i < after.size(); i++) {
        out.pb(after[i]);
    }

    // Check if works
    return area(out) >= target;
}

int main() {
    //file();
    //fast();

    int n;
    cin >> n;

    double d, l;
    cin >> d >> l;

    double hi = -2005;
    double lo = 2005;
    deque<coord> v(n);
    for(auto& i : v) {
        cin >> i.x >> i.y;
        hi = max(hi, i.y);
        lo = min(lo, i.y);

    }

    // Make sure rotated correctly
    while(v.front().y != 0 || v.back().y != 0) {
        v.push_back(v.front());
        v.pop_front();
    }

    // Binary search on answer
    double target = (l*1000) / d; // target is area desired
    while(abs(hi - lo) > .00001) {
        double mid = (hi-lo)/2 + lo;
        if(calc(v, mid, target)) {
            hi = mid;
        }
        else {
            lo = mid;
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << lo << endl;
}
