#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    int cases;
    cin >> cases;

    while(cases--) {
        ll a, b, c;
        cin >> a >> b >> c;

        ll s = __gcd(a, b);

        if(c % s == 0) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}
