#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
ll inf = (ll) 2 << 60;

int main() {
    ll n;
    cin >> n;

    vector<ll> teas(n);
    for(auto& i : teas) {
        cin >> i;
    }

    ll m;
    cin >> m;

    vector<ll> toppings(m);
    for(auto& i : toppings) {
        cin >> i;
    }

    ll best = inf;
    for(ll i = 0; i < n; i++) {
        ll p;
        cin >> p;

        for(ll j = 0; j < p; j++) {
            ll temp;
            cin >> temp;

            best = min(best, teas[i] + toppings[temp-1]);
        }
    }

    ll total;
    cin >> total;

    ll ans = (total / best) - 1;
    ans = max(ans, (ll)0);

    cout << ans << endl;
}
