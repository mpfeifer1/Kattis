#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    ll d, n;
    cin >> d >> n;

    vector<ll> v = {0};
    vector<ll> p = {0};
    for(int i = 1; i <= n; i++) {
        int t; cin >> t;
        v.push_back(t);
        p.push_back((p.back() + t)%d);
    }

    ll ans = 0;
    map<ll,ll> buckets;
    buckets[0] = 1;
    for(int i = 1; i <= n; i++) {
        ans += buckets[p[i]%d];
        buckets[p[i]%d]++;
    }

    cout << ans << endl;
}

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        solve();
    }
}
