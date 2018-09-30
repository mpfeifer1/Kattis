#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// Factorize a number
map<ll,ll> factorize(ll n) {
    map<ll,ll> fact;
    for(ll i = 2; i*i <= n; i++) {
        while(n % i == 0) {
            n /= i;
            fact[i]++;
        }
    }
    if(n > 1) {
        fact[n]++;
    }
    return fact;
}

int main() {
    // Fast IO
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;

    // Read in input
    vector<ll> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    // Get all numbers factorizations
    vector<map<ll,ll>> facts;
    for(auto i : v) {
        facts.push_back(factorize(i));
    }

    // For all factorizations, add their factors to a big sum
    map<ll,ll> big;
    for(auto i : facts) {
        for(auto j : i) {
            big[j.first] += j.second;
        }
    }

    // Turn the big sum into the biggest possible GCD
    for(auto& i : big) {
        i.second /= n;
    }

    // Remove any zeros
    vector<ll> rem;
    for(auto i : big) {
        if(i.second == 0) {
            rem.push_back(i.first);
        }
    }
    for(auto i : rem) {
        big.erase(i);
    }

    // Calculate the final value
    ll val = 1;
    for(auto i : big) {
        val *= pow(i.first, i.second);
    }

    // Calculate number of operations to achieve it
    ll ops = 0;
    for(auto i : facts) {
        for(auto j : big) {
            if(big[j.first] > i[j.first]) {
                ops += big[j.first] - i[j.first];
            }
        }
    }

    // Print the answer
    cout << val << " " << ops << endl;
}
