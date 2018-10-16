#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    n--;
    m--;

    int lcm = n * m / __gcd(n, m);
    int ans = lcm + 1 - ((lcm / n - 1) * (lcm / m - 1) / 2);
    cout << ans << endl;
}

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        solve();
    }
}
