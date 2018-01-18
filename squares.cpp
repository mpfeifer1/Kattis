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




/***RAT************************************/

struct rat {
    ll top;
    ll bot;
};

bool operator<(const rat& x, const rat& y) {
    return tie(x.top, x.bot) < tie(y.top, y.bot);
}

void simplify(rat& r) {
    ll gcd = __gcd(r.top, r.bot);
    r.top /= gcd;
    r.bot /= gcd;

    if(r.bot < 0) {
        r.top *= -1;
        r.bot *= -1;
    }

    if(r.top == 0) {
        r.bot = 1;
    }

    if(r.bot == 0) {
        r.top = 1;
    }
}

rat perp(rat r) {
    simplify(r);
    rat ret = {-r.bot, r.top};
    simplify(ret);
    return ret;
}

rat multiply(rat r1, rat r2) {
    simplify(r1);
    simplify(r2);
    rat ret = {r1.top * r2.top, r1.bot * r2.bot};
    simplify(ret);
    return ret;
}

rat multiply(rat r1, ll i) {
    simplify(r1);
    rat ret = {r1.top * i, r1.bot};
    simplify(ret);
    return ret;
}

rat divide(rat r1, rat r2) {
    simplify(r1);
    simplify(r2);
    rat ret = {r1.top * r2.bot, r1.bot * r2.top};
    simplify(ret);
    return ret;
}

rat add(rat r1, ll i) {
    simplify(r1);
    rat ret = {r1.top + (i * r1.bot), r1.bot};
    simplify(ret);
    return ret;
}

rat sub(rat r1, rat r2) {
    ll bot1 = r1.bot;
    ll bot2 = r2.bot;

    r1.top *= bot2;
    r1.bot *= bot2;

    r2.top *= bot1;
    r2.bot *= bot2;

    rat r = {r1.top - r2.top, r1.bot};
    simplify(r);
    return r;
}

rat abs(rat r) {
    simplify(r);
    if(r.top < 0) {
        r.top *= -1;
    }
    simplify(r);
    return r;
}

rat neg(rat r) {
    r.top *= -1;
    simplify(r);
    return r;
}

ostream& operator<<(ostream& o, const rat& r) {
    return o << r.top << "/" << r.bot;
}

struct line {
    rat slope;
    ll x1, x2, y1, y2;
};

/***HELPER*********************************/

ld myround(ld i) {
    i *= 1024;
    i = round(i);
    i /= 1024;
    return i;
}

map<rat,ll> getdist(vector<line> v, rat slope) {
    vector<rat> intercepts;

    for(auto i : v) {
        rat r = add(multiply(slope, i.x1), -i.y1);
        //r = divide(r, slope);

        intercepts.push_back(r);
    }

    map<rat,ll> ret;
    for(ll i = 0; i < intercepts.size(); i++) {
        for(ll j = i+1; j < intercepts.size(); j++) {
            ret[abs(sub(intercepts[i], intercepts[j]))]++;
        }
    }

    return ret;
}

ll calc(vector<line> v1, vector<line> v2) {
    map<ll,ll> dist1, dist2;

    for(ll i = 0; i < v1.size(); i++) {
        for(ll j = i+1; j < v1.size(); j++) {
            dist1[abs(v1[i].x1 - v1[j].x1)]++;
        }
    }

    for(ll i = 0; i < v2.size(); i++) {
        for(ll j = i+1; j < v2.size(); j++) {
            dist2[abs(v2[i].y1 - v2[j].y1)]++;
        }
    }

    ll total = 0;
    for(auto i : dist1) {
        total += dist1[i.first] * dist2[i.first];
    }

    return total;
}

/***MAIN***********************************/

int main() {
    //file();
    fast();


/***INPUT**********************************/

    ll n;
    cin >> n;
    vector<line> v(n);
    for(auto& i : v) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if(x1 > x2) {
            swap(x1, x2);
            swap(y1, y2);
        }
        rat slope = {(y2-y1), (x2-x1)};
        simplify(slope);
        i.slope = slope;

        i.x1 = x1;
        i.x2 = x2;
        i.y1 = y1;
        i.y2 = y2;
    }

/***SPLIT**********************************/

    map<rat, vector<line>> slopes;
    for(auto i : v) {
        slopes[i.slope].pb(i);
    }

/***GROUP**********************************/

    ll total = 0;
    while(!slopes.empty()) {
        auto it = slopes.begin();
        rat slope = it->first;
        rat recip = perp(slope);

        // Grab lines, remove them
        vector<line> v1 = slopes[slope];
        vector<line> v2 = slopes[recip];

        slopes.erase(slope);
        slopes.erase(recip);

        // Horiz / Vert slope
        if(slope.top == 0 || slope.bot == 0) {
            if(slope.top == 0) {
                swap(v1, v2);
            }
            total += calc(v1, v2);
        }

        // Angled slope
        else {
            map<rat,ll> dist1, dist2;

            dist1 = getdist(v1, slope);
            dist2 = getdist(v2, recip);

            for(auto i : dist1) {
                total += dist1[i.first] * dist2[multiply(i.first, recip)];
            }
        }
    }

    cout << total << endl;
}
