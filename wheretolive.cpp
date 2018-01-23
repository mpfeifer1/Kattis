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





struct point {
    int x, y;
};

int calc(vector<point>& v, int x, int y) {
    int total = 0;
    for(auto i : v) {
        int xdiff = abs(x-i.x);
        int ydiff = abs(y-i.y);
        total += (xdiff * xdiff) + (ydiff * ydiff);
    }
    return total;
}

int main() {
    //file();
    //fast();

    int n;
    while(cin >> n && n != 0) {
        // Read in input
        vector<point> v(n);
        for(auto& i : v) {
            cin >> i.x >> i.y;
        }

        // Find minimum x and y coords
        int minx = v[0].x;
        int miny = v[0].y;
        for(int i = 1; i < v.size(); i++) {
            minx = min(minx, v[i].x);
            miny = min(miny, v[i].y);
        }

        // Set up current state
        int currx = minx;
        int curry = miny;
        int currval = calc(v, currx, curry);

        // While there's a better option, take it
        while(true) {
            int up = calc(v, currx, curry+1);
            int rt = calc(v, currx+1, curry);

            if(up < currval || rt < currval) {
                if(up < rt) {
                    currval = up;
                    curry++;
                }
                else {
                    currval = rt;
                    currx++;
                }
                continue;
            }

            break;
        }

        // Print found answer
        cout << currx << " " << curry << endl;
    }

}
