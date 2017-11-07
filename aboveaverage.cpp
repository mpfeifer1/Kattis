#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ll cases;
    cin >> cases;

    while(cases--) {
        ll s;
        cin >> s;

        vector<ll> students(s);

        for(auto& i : students) {
            cin >> i;
        }

        ll total = 0;
        for(auto i : students) {
            total += i;
        }

        ll better = 0;
        ld average = total / ld(s);
        for(auto i : students) {
            if(i > average) {
                better++;
            }
        }

        cout << fixed;
        cout.precision(3);
        cout << 100 * better / double(s) << "%" << endl;
    }
}
