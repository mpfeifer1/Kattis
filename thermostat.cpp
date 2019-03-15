#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct rat {
    ll top;
    ll bot;
};

bool operator<(const rat& x, const rat& y) {
    return x.top * y.bot < y.top * x.bot;
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

rat mul(rat r1, rat r2) {
    simplify(r1);
    simplify(r2);
    rat ret = {r1.top * r2.top, r1.bot * r2.bot};
    simplify(ret);
    return ret;
}

rat mul(rat r1, ll i) {
    return mul(r1,{i,1});
}

rat div(rat r1, rat r2) {
    simplify(r1);
    simplify(r2);
    rat ret = {r1.top * r2.bot, r1.bot * r2.top};
    simplify(ret);
    return ret;
}

rat div(rat r1, ll i) {
    return div(r1,{i,1});
}

rat add(rat r1, rat r2) {
    simplify(r1);
    simplify(r2);

    ll bot1 = r1.bot;
    ll bot2 = r2.bot;

    r1.top *= bot2;
    r1.bot *= bot2;

    r2.top *= bot1;
    r2.bot *= bot2;

    rat r = {r1.top + r2.top, r1.bot};
    simplify(r);
    return r;
}

rat add(rat r1, ll i) {
    return add(r1,{i,1});
}

rat sub(rat r1, rat r2) {
    simplify(r1);
    simplify(r2);

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

rat sub(rat r1, ll i) {
    return sub(r1,{i,1});
}

rat perpendicular(rat r) {
    simplify(r);
    rat ret = {-r.bot, r.top};
    simplify(ret);
    return ret;
}

rat abs(rat r) {
    simplify(r);
    if(r.top < 0) {
        r.top *= -1;
    }
    simplify(r);
    return r;
}

ostream& operator<<(ostream& o, const rat& r) {
    return o << r.top << "/" << r.bot;
}

ll getd(rat p) {
    return p.bot - p.top;
}

void solve(rat base1, rat base2, ll n) {
    ll diff1 = getd(base1);
    ll diff2 = getd(base2);

    n -= base1.top;

    rat p = {n,diff1};

    p = mul(p,diff2);
    p = add(p,base2.top);

    cout << p << endl;
}

int main() {
    ll n, q;
    cin >> n >> q;

    vector<rat> bases(n);
    for(auto& i : bases) {
        cin >> i.top >> i.bot;
    }

    for(ll i = 0; i < q; i++) {
        ll b1, b2, n;
        cin >> b1 >> b2 >> n;
        solve(bases[b1-1],bases[b2-1],n);
    }
}
