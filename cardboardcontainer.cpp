#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    int n;
    cin >> n;
    vector<int> factors;
    for(int i = 1; i*i <= n; ++i) {
        if(n%i == 0) {
            factors.push_back(i);
            if(i*i != n) factors.push_back(n/i);
        }
    }
    sort(factors.begin(), factors.end());
    int res = 1e18;
    for(int f : factors) {
        const int l = f;
        int remaining = n/f;
        for(int f2 : factors) {
            if(remaining%f2 != 0) continue;
            const int w = remaining/f2;
            const int h = f2;
            assert(l*w*h == n);
            res = min(res, 2LL*(l*w+w*h+h*l));
        }
    }
    cout << res << '\n';
    return 0;
}
