#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    // Setup
    vector<bool> primes(n+1, true);
    primes[0] = false;
    primes[1] = false;
    int m = sqrt(n);
    int count = 0;

    // Prime sieve
    for(int i = 2; i <= m; i++) {
        if(primes[i]) {
            count++;
            for(int j = i*2; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }

    // Count extra primes
    for(int i = m+1; i <= n; i++) {
        if(primes[i]) {
            count++;
        }
    }

    // Print count of primes
    cout << count << endl;

    // Answer all queries
    for(int i = 0; i < q; i++) {
        int query;
        cin >> query;

        cout << primes[query] << endl;
    }
}
