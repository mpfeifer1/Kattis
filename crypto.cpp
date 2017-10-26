#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;

vector<ll> primefactors(ll n) {
    ll o = n;

    vector<ll> factors;
    while(n % 2 == 0) {
        factors.push_back(2);
        n >>= 1;
    }

    for(ll i = 3; i <= sqrt(n)+1; i+=2) {
        while(n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    if(n == o) {
        factors.push_back(n);
    }

    return factors;
}

int main() {
    ll n;
    cin >> n;

    vector<ll> factors = primefactors(n);

    // Count factors
    map<ll, ll> m;
    for(auto i : factors) {
        m[i]++;
    }

    // Find most frequent factor
    ll bestcount= -1;
    ll best = -1;
    for(auto i : m) {
        if(i.second > bestcount) {
            bestcount = i.second;
            best = i.first;
        }
    }

    // Print answer
    cout << best << endl;
}
