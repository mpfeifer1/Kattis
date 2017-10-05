#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<bool> primes;
    primes.resize(32100, true);
    primes[0] = false;
    primes[1] = false;

    // Prime Sieve
    for(int i = 2; i < 32100; i++) {
        if(!primes[i]) {
            continue;
        }
        for(int j = i+1; j < 32100; j++) {
            if(j % i == 0) {
                primes[j] = false;
            }
        }
    }

    // Solve
    int cases;
    cin >> cases;
    for(int i = 0; i < cases; i++) {
        int num;
        cin >> num;

        vector<pair<int, int>> reps;
        for(int i = 2; i <= num/2; i++) {
            if(primes[i] && primes[num-i]) {
                reps.push_back({i, num-i});
            }
        }

        cout << num << " has " << reps.size() << " representation(s)" << endl;
        for(auto i : reps) {
            cout << i.first << "+" << i.second << endl;
        }
        cout << endl;
    }
}
