#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll n, k;
    cin >> n >> k;

    ll total = n * (n+1) / 2;

    vector<ll> houses;
    houses.push_back(0);
    for(ll i = 0; i < k; i++) {
        ll t;
        cin >> t;
        houses.push_back(t);
    }
    houses.push_back(n+1);

    for(ll i = 1; i < houses.size(); i++) {
        ll diff = houses[i] - houses[i-1] - 1;
        total -= diff * (diff + 1) / 2;
    }

    cout << total << endl;
}
