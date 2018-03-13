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





struct card {
    ll r, g, b;
    ll id;
    ll uni;
};

ostream& operator << (ostream& o, const card& c) {
    o << c.r << "\t" << c.g << "\t" << c.b << "\t" << c.uni << "\t" << c.id;
    return o;
}

struct r_cmp {
    bool operator() (const card& lhs, const card& rhs) {
        if(lhs.r == rhs.r) {
            return lhs.id < rhs.id;
        }
        return lhs.r < rhs.r;
    }
};

struct g_cmp {
    bool operator() (const card& lhs, const card& rhs) {
        if(lhs.g == rhs.g) {
            return lhs.id < rhs.id;
        }
        return lhs.g < rhs.g;
    }
};

struct b_cmp {
    bool operator() (const card& lhs, const card& rhs) {
        if(lhs.b == rhs.b) {
            return lhs.id < rhs.id;
        }
        return lhs.b < rhs.b;
    }
};

struct uni_cmp {
    bool operator() (const card& lhs, const card& rhs) {
        if(lhs.uni == rhs.uni) {
            return lhs.id > rhs.id;
        }
        return lhs.uni < rhs.uni;
    }
};

set<card, r_cmp> r;
set<card, g_cmp> g;
set<card, b_cmp> b;
set<card, uni_cmp> uni;

ll angle(char color, card c, card c1, card c2) {
    ll l = 0, r = 0, m = 0;
    if(color == 'r') {
        l = c1.r;
        r = c2.r;
        m = c.r;
    }
    if(color == 'g') {
        l = c1.g;
        r = c2.g;
        m = c.g;
    }
    if(color == 'b') {
        l = c1.b;
        r = c2.b;
        m = c.b;
    }

    if(m == l || m == r) {
        return 0;
    }

    r += 360;
    r -= l;
    while(r > 360) r -= 360;

    return r;
}

template <class T>
pair<card,card> getsurrounding(set<card, T>& s, card c) {
    auto it = s.find(c);
    card r1, r2;

    // Get previous
    if(it == s.begin()) {
        r1 = *prev(s.end());
    }
    else {
        r1 = *prev(it);
    }

    // Get next
    if(it == prev(s.end())) {
        r2 = *s.begin();
    }
    else {
        r2 = *next(it);
    }

    return {r1,r2};
}

// Takes in a card, recalculates its uniqueness val, reinserts it into sets
void calc(card c) {
    if(uni.find(c) == uni.end()) {
        return;
    }

    card t = c;
    t.uni = 0;

    // Get red uniqueness
    pair<card,card> rcard = getsurrounding(r, c);
    t.uni += angle('r', c, rcard.first, rcard.second);

    // Get green uniqueness
    pair<card,card> gcard = getsurrounding(g, c);
    t.uni += angle('g', c, gcard.first, gcard.second);

    // Get blue uniqueness
    pair<card,card> bcard = getsurrounding(b, c);
    t.uni += angle('b', c, bcard.first, bcard.second);

    uni.erase(c);
    uni.insert(t);

    r.erase(c);
    r.insert(t);

    g.erase(c);
    g.insert(t);

    b.erase(c);
    b.insert(t);
}

int main() {
    //file();
    fast();

    ll n;
    cin >> n;

    vector<card> all;
    for(ll i = 0; i < n; i++) {
        card c;
        cin >> c.r >> c.g >> c.b >> c.id;

        r.insert(c);
        g.insert(c);
        b.insert(c);
        uni.insert(c);

        all.pb(c);
    }

    for(auto i : all) {
        calc(i);
    }

    while(!uni.empty()) {
        card c = *uni.begin();
        cout << c.id << endl;

        pair<card,card> rsurround = getsurrounding(r, c);
        pair<card,card> gsurround = getsurrounding(g, c);
        pair<card,card> bsurround = getsurrounding(b, c);

        uni.erase(c);
        r.erase(c);
        g.erase(c);
        b.erase(c);

        if(uni.empty()) {
            break;
        }

        set<card, uni_cmp> tofix;

        tofix.insert(rsurround.first);
        tofix.insert(rsurround.second);
        tofix.insert(gsurround.first);
        tofix.insert(gsurround.second);
        tofix.insert(bsurround.first);
        tofix.insert(bsurround.second);

        for(auto i : tofix) {
            calc(i);
        }
    }

    return 0;
}
