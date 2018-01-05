#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll n, p;
    cin >> n >> p;

    vector<ll> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    sort(v.begin(), v.end());

    ll dist = 0;
    for(ll i = 0; i < v.size(); i++) {
        ll dist_to_keep = p * (i+1);
        ll dist_already = v[i];
        dist = max(dist, dist_to_keep - dist_already);
    }

    cout << dist + v[0] << endl;
}
