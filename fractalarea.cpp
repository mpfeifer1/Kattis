#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    ld r;
    ll n;
    cin >> r >> n;

    ld currarea = M_PI * r * r;
    ld currcircles = 4;

    ld ans = 0;
    ans += currarea;

    ld curradd = currarea * currcircles / 4;

    for(ll i = 0; i < n-1; i++) {
        ans += curradd;
        curradd *= .75;
    }

    cout << fixed;
    cout.precision(8);
    cout << ans << endl;
}

int main() {
    ll cases;
    cin >> cases;
    while(cases--) {
        solve();
    }
}


