#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;

    if(n == 1) {
        cout << "no" << endl;
        return 0;
    }

    vector<ll> factors;
    while(n % 2 == 0) {
        factors.push_back(2);
        n >>= 1;
    }
    for(ll i = 3; i <= sqrt(n) + 1; i += 2) {
        while(n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if(n != 1) {
        factors.push_back(n);
    }

    for(int i = 1; i < factors.size(); i++) {
        if(factors[i-1] != factors[i]) {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
}
