#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct rat;
bool operator<(const rat& x, const rat& y);
rat operator*(rat r1, rat r2);
rat operator*(rat r1, ll i);
rat operator/(rat r1, rat r2);
rat operator/(rat r1, ll i);
rat operator+(rat r1, rat r2);
rat operator+(rat r1, ll i);
rat operator-(rat r1, rat r2);
rat operator-(rat r1, ll i);
rat perpendicular(rat r);
rat abs(rat r);
rat neg(rat r);
void simplify(rat& r);

struct rat {
    ll top;
    ll bot;

    rat(ll l) {
        top = l;
        bot = 1;
    };
    rat(ll a, ll b) {
        top = a;
        bot = b;
    }
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

rat operator*(rat r1, rat r2) {
    simplify(r1);
    simplify(r2);
    rat ret = {r1.top * r2.top, r1.bot * r2.bot};
    simplify(ret);
    return ret;
}

rat operator*(rat r1, ll i) {
    simplify(r1);
    rat ret = {r1.top * i, r1.bot};
    simplify(ret);
    return ret;
}

rat operator/(rat r1, rat r2) {
    simplify(r1);
    simplify(r2);
    rat ret = {r1.top * r2.bot, r1.bot * r2.top};
    simplify(ret);
    return ret;
}

rat operator/(rat r1, ll i) {
    simplify(r1);
    rat ret = {r1.top, r1.bot * i};
    simplify(ret);
    return ret;
}

rat operator+(rat r1, rat r2) {
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

rat operator+(rat r1, ll i) {
    simplify(r1);
    rat ret = {r1.top + (i * r1.bot), r1.bot};
    simplify(ret);
    return ret;
}

rat operator-(rat r1, rat r2) {
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

rat operator-(rat r1, ll i) {
    simplify(r1);
    rat ret = {r1.top - (i * r1.bot), r1.bot};
    simplify(ret);
    return ret;
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

rat neg(rat r) {
    simplify(r);
    r.top *= -1;
    simplify(r);
    return r;
}

ostream& operator<<(ostream& o, const rat& r) {
    return o << r.top << "/" << r.bot;
}

int main() {
    int terms;
    cin >> terms;

    vector<int> v(terms);
    for(auto& i : v) cin >> i;

    rat ans = rat(v[terms-1]);
    rat one = rat(1,1);

    for(int i = terms-2; i >= 0; i--) {
        ans = rat(v[i]) + (one / ans);
    }

    cout << ans << endl;
}
