#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;

    vector<ll> p;
    for(ll i = 1; i < sqrt(n)+2; i++) {
        if(n % i == 0) {
            p.push_back(i);
            p.push_back(n/i);
        }
    }

    sort(p.begin(), p.end());

    p.resize(distance(p.begin(), unique(p.begin(), p.end())));

    for(auto i : p) {
        cout << i-1 << " ";
    }
    cout << endl;
}
