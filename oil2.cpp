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
const ld  prec = .0000000001;

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





int n;

struct segment {
    int l, r, h;
};

struct point {
    int x, y, val;
    ld angle;
};

void getangle(point& ref, point& p) {
    int dx = p.x - ref.x;
    int dy = p.y - ref.y;

    p.angle = atan2l((ld)dy, (ld)dx) * 180/M_PI;
}

bool cmp(point p1, point p2) {
    if(abs(p1.angle-p2.angle) < prec) {
        return p1.val > p2.val;
    }

    return p1.angle < p2.angle;
}

ll solve(point p, point actual[4000], int sz) {
    point real[4000];
    for(int j = 0; j < sz; j++) {
        point i = actual[j];
        if(i.y > p.y) {
            int ydiff = i.y - p.y;
            int xdiff = i.x - p.x;
            i.y -= 2*ydiff;
            i.x -= 2*xdiff;
        }
        getangle(p,i);
        real[j] = i;
    }

    sort(real, real+sz, cmp);

    ll val = abs(p.val);
    ll best = val;
    for(int j = 0; j < sz; j++) {
        point i = real[j];
        val += i.val;
        best = max(best, val);
    }

    return best;
}

ll process(int p, segment v[2000]) {
    point actual[4000];
    int sz = 0;

    for(int i = 0; i < n; i++) {
        if(v[i].h == v[p].h) continue;

        int l = v[i].l;
        int r = v[i].r;
        int h = v[i].h;

        if(v[i].h > v[p].h) {
            actual[sz] = {l,h,l-r};
            sz++;
            actual[sz] = {r,h,r-l};
            sz++;
        }
        else {
            actual[sz] = {l,h,r-l};
            sz++;
            actual[sz] = {r,h,l-r};
            sz++;
        }
    }

    ll best = 0;

    int l = v[p].l;
    int r = v[p].r;
    int h = v[p].h;

    best = max(best, solve({l, h, r-l}, actual, sz));
    best = max(best, solve({r, h, r-l}, actual, sz));

    return best;
}

int main() {
    //file();
    fast();

    cin >> n;

    segment v[2000];

    for(int i = 0; i < n; i++) {
        int l, r, h;
        cin >> l >> r >> h;

        if(l > r) {
            swap(l,r);
        }

        v[i] = {l,r,h};
    }

    ll best = 0;
    for(int i = 0; i < n; i++) {
        best = max(best, process(i, v));
    }

    cout << best << endl;

    return 0;
}

