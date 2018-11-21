#include <bits/stdc++.h>

using namespace std;

void solve() {
    int k, b, n;
    cin >> k >> b >> n;

    int ans = 0;
    while(n > 0) {
        ans += (n % b) * (n % b);
        n /= b;
    }

    cout << k << " " << ans << endl;
}

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        solve();
    }
}
