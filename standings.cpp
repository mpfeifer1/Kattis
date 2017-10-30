#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
    ll cases;
    cin >> cases;

    while(cases--) {
        ll n;
        cin >> n;
        vector<ll> v(n);

        for(auto& i : v) {
            string s;
            cin >> s >> i;
        }

        sort(v.begin(), v.end());

        ll total = 0;
        for(ll i = 0; i < n; i++) {
            total += abs(v[i] - (i+1));
        }

        cout << total << endl;
    }
}
