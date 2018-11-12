#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = (ll)1 << 61;

int main() {
    ll lo = inf;
    ll idx = 0;

    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++) {
        ll t;
        cin >> t;
        if(t < lo) {
            lo = t;
            idx = i;
        }
    }

    cout << idx << endl;
}
