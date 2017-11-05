#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ll cases;
    cin >> cases;

    while(cases--) {
        ll c;
        cin >> c;

        vector<ld> v;

        for(ll i = 0; i < c; i++) {
            ll nums;
            cin >> nums;

            ld total = 0;
            for(ll i = 0; i < nums; i++) {
                ld temp;
                cin >> temp;
                total += temp;
            }

            v.push_back(total);
        }

        sort(v.begin(), v.end());

        ld sum = 0;
        ld ans = 0;
        for(ll i = 0; i < v.size(); i++) {
            sum += v[i];
            ans += sum;
        }
        ans /= v.size();

        cout << fixed;
        cout.precision(9);
        cout << ans << endl;
    }
}
