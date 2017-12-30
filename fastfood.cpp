#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll cases;
    cin >> cases;

    while(cases--) {
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> v(n);
        vector<ll> values(n);

        for(ll i = 0; i < n; i++) {
            ll k;
            cin >> k;
            v[i].resize(k);
            for(auto& j : v[i]) {
                cin >> j;
                j--;
            }
            cin >> values[i];
        }

        vector<ll> all(m);
        for(auto& i : all) {
            cin >> i;
        }

        ll total = 0;
        for(ll i = 0; i < n; i++) {
            ll lo = all[v[i][0]];
            for(auto j : v[i]) {
                lo = min(lo, all[j]);
            }

            total += lo * values[i];
        }

        cout << total << endl;
    }
}
