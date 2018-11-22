#include <bits/stdc++.h>

using namespace std;
typedef long double ld;

int main() {
    ld ans = 0;
    ld curr = 1;

    int n;
    cin >> n;
    if(n > 30) n = 30;
    for(int i = 1; i <= n+1; i++) {
        ans += 1 / curr;
        curr *= i;
    }

    cout << fixed;
    cout.precision(15);
    cout << ans << endl;
}
