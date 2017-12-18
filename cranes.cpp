#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

struct crane {
    ll x;
    ll y;
    ll r;
};

bool touch(crane c1, crane c2) {
    ld dist = sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
    return (dist <= (c1.r + c2.r));
}

ll calc(vector<vector<bool>>& c, vector<crane>& v, ll i) {
    vector<ll> use;

    ll curr = 0;
    while(i > 0) {
        if(i % 2 == 1) {
            use.push_back(curr);
        }
        i >>= 1;
        curr++;
    }

    bool works = true;
    for(ll i = 0; i < use.size() && works; i++) {
        for(ll j = i+1; j < use.size() && works; j++) {
            if(i == j) {
                continue;
            }
            if(c[use[i]][use[j]]) {
                works = false;
            }
        }
    }

    if(works) {
        ll total = 0;
        for(auto i : use) {
            ll here = v[i].r;
            total += here*here;
        }
        return total;
    }
    return 0;
}

int main() {
    ll cases;
    cin >> cases;

    while(cases--) {
        ll n;
        cin >> n;

        vector<crane> v(n);
        for(auto& i : v) {
            cin >> i.x >> i.y >> i.r;
        }

        vector<vector<bool>> collision;
        collision.resize(n, vector<bool>(n,false));
        for(ll i = 0; i < n; i++) {
            for(ll j = 0; j < n; j++) {
                if(i==j) {
                    continue;
                }
                collision[i][j] = touch(v[i],v[j]);
            }
        }

        ll best = 0;
        for(ll i = 1; i < (1<<n); i++) {
            best = max(best, calc(collision, v, i));
        }

        cout << best << endl;
    }
}
