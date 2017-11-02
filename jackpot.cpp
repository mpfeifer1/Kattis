#include <unordered_map>
#include <iostream>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;

int main() {
    ll cases;
    cin >> cases;

    while(cases--) {
        ll items;
        cin >> items;

        map<ll, ll> bestfactors;

        for(ll i = 0; i < items; i++) {
            ll item;
            cin >> item;

            map<ll, ll> factorshere;

            while(item > 1) {
                bool broken = false;
                for(ll j = 2; j <= sqrt(item) + 1; j++) {
                    if(item % j == 0) {
                        item /= j;
                        factorshere[j]++;
                        broken = true;
                        break;
                    }
                }

                if(!broken) {
                    factorshere[item]++;
                    item = 1;
                }
            }

            for(auto i : factorshere) {
                ll idx = i.first;
                if(factorshere[idx] > bestfactors[idx]) {
                    bestfactors[idx] = factorshere[idx];
                }
            }
        }

        ll total = 1;
        bool toobig = false;
        for(auto i : bestfactors) {
            total *= pow(i.first, i.second);
            if(total > 1000000000) {
                toobig = true;
                break;
            }
        }

        if(toobig) {
            cout << "More than a billion." << endl;
        }
        else {
            cout << total << endl;
        }
    }
}
