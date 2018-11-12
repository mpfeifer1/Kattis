#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    map<ll,vector<ll>> m;
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++) {
        ll t;
        cin >> t;
        m[t].push_back(i);
    }

    ll ans = n;
    for(auto i : m) {
        for(ll j = 1; j < i.second.size(); j++) {
            ans = min(ans, ll(i.second[j] - i.second[j-1]));
        }
    }

    cout << ans << endl;
}
