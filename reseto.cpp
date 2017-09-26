#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<bool> v;
    v.resize(n+1, true);

    v[0] = false;
    v[1] = false;

    int crosses = 0;

    for(int i = 2; i <= n; i++) {
        // If not prime, continue
        if(!v[i]) {
            continue;
        }

        // If prime, cross it out, then sieve
        for(int j = i; j <= n; j+=i) {
            // If crossed, skip
            if(!v[j]) {
                continue;
            }

            // Otherwise, cross
            v[j] = false;
            crosses++;

            // If crossed enough, quit
            if(crosses == k) {
                cout << j << endl;
                return 0;
            }
        }
    }
}
