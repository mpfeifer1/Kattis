#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int ans = 1;
    for(int i = 1; i <= n; i++) {
        ans *= i;
        ans %= 10;
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
