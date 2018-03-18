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

rat perpendicular(rat r) {
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



int main() {
    //file();
    //fast();

    rat r;
    cin >> r.top;
    cin.ignore();
    cin >> r.bot;

    rat t1 = {32,1};
    r = sub(r, t1);

    rat t2 = {9,5};
    r = divide(r, t2);

    cout << r << endl;

    return 0;
}
