#include <bits/stdc++.h>

using namespace std;
typedef long double ld;

int main() {
    int n;
    cin >> n;

    ld ans = 0;
    for(int i = 0; i < n; i++) {
        ld l, r;
        cin >> l >> r;
        ans += l*r;
    }

    cout << fixed;
    cout.precision(4);
    cout << ans << endl;
}
