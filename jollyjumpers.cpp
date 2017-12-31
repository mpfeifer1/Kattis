#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    while(cin >> n) {
        vector<ll> v(n);
        for(auto& i : v) {
            cin >> i;
        }

        vector<bool> seen(n, false);

        for(ll i = 1; i < n; i++) {
            ll diff = abs(v[i] - v[i-1]);
            if(diff >= 0 && diff < n) {
                seen[diff] = true;
            }
        }

        bool works = true;
        for(int i = 1; i < n; i++) {
            works &= seen[i];
        }

        if(works) {
            cout << "Jolly" << endl;
        }
        else {
            cout << "Not jolly" << endl;
        }
    }
}
