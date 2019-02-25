#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll cieldiv(ll top, ll bot) {
    return (top + bot - 1) / bot;
}

ll ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
	ll dx1 = b.first - a.first;
	ll dy1 = b.second - a.second;
	ll dx2 = c.first - a.first;
	ll dy2 = c.second - a.second;
	return dx1 * dy2 - dy1 * dx2;
}

int main() {
    ll n, p;
    cin >> n >> p;

    vector<pair<ll,ll>> coords(n);
    for(auto& i : coords) {
        cin >> i.first >> i.second;
    }

    ll target = cieldiv(n*p,100);

    if(n <= 2) {
        cout << "possible" << endl;
        return 0;
    }

    for(ll i = 0; i < 300; i++) {
        ll n1 = rand() % n;
        ll n2 = rand() % n;
        if(n1 == n2) continue;

        ll ct = 0;
        for(ll j = 0; j < n; j++) {
            if(ccw(coords[n1],coords[n2],coords[j]) == 0) {
                ct++;
            }
        }

        if(ct >= target) {
            cout << "possible" << endl;
            return 0;
        }
    }

    cout << "impossible" << endl;
}
