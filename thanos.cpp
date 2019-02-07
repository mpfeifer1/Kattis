#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll ct = 0;
    while(a <= c) {
        a *= b;
        ct++;
    }
    cout << ct << endl;
}

int main() {
    ll cases;
    cin >> cases;
    while(cases--) {
        solve();
    }
}
