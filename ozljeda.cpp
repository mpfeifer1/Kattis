#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;

    // Build entire cyclic array
    vector<ll> vals(n);
    ll total = 0;
    for(auto& i : vals) {
        cin >> i;
        total ^= i;
    }
    vals.push_back(total);
    n++;

    // Build prefix sums from l and r
    ll sum;
    sum = 0;
    vector<ll> suml(n);
    for(int i = 0; i < n; i++) {
        sum ^= vals[i];
        suml[i] = sum;
    }
    sum = 0;
    vector<ll> sumr(n);
    for(int i = n-1; i >= 0; i--) {
        sum ^= vals[i];
        sumr[i] = sum;
    }

    // Process the queries
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        ll n1, n2;
        cin >> n1 >> n2;
        n1--; n2--;

        n1 %= n;
        n2 %= n;

        ll ans = 0;
        ans ^= suml[n2];
        ans ^= sumr[n1];

        cout << ans << endl;
    }
}
