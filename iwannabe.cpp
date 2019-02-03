#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct poke {
    ll a, d, h;
};

bool cmpa(poke& p1, poke& p2) {
    return p1.a > p2.a;
}

bool cmpd(poke& p1, poke& p2) {
    return p1.d > p2.d;
}

bool cmph(poke& p1, poke& p2) {
    return p1.h > p2.h;
}

bool operator<(const poke& p1, const poke& p2) {
    return tie(p1.a,p1.d,p1.h) < tie(p2.a,p2.d,p2.h);
}

int main() {
    ll n, m;
    cin >> n >> m;

    vector<poke> v(n);
    for(auto& i : v) {
        cin >> i.a >> i.d >> i.h;
    }

    set<poke> all;

    sort(v.begin(),v.end(),cmpa);
    for(ll i = 0; i < m; i++) {
        all.insert(v[i]);
    }

    sort(v.begin(),v.end(),cmpd);
    for(ll i = 0; i < m; i++) {
        all.insert(v[i]);
    }

    sort(v.begin(),v.end(),cmph);
    for(ll i = 0; i < m; i++) {
        all.insert(v[i]);
    }

    cout << all.size() << endl;
}
