#include <bits/stdc++.h>

using namespace std;

map<tuple<vector<int>,vector<int>,int>,double> memo;

double prob(vector<int> good, vector<int> bad, int d) {
    // If already memoized, use that
    if(memo.count({good,bad,d})) {
        return memo[{good,bad,d}];
    }

    // If all the bad guys are dead, 100% chance of winning
    bool dead = true;
    for(int i = 1; i < 7; i++) {
        if(bad[i] > 0) dead = false;
    }
    if(dead) {
        memo[{good,bad,d}] = 1;
        return 1;
    }

    // If not enough damage left to use, 0% chance of winning
    int needed = 0;
    for(int i = 0; i < 7; i++) {
        needed += bad[i] * i;
    }
    if(d < needed) {
        memo[{good,bad,d}] = 0;
        return 0;
    }

    // Otherwise, calculate the probability for each guy
    // getting hit
    vector<double> probs;

    for(int i = 1; i < 7; i++) {
        if(good[i] > 0) {
            good[i]--;
            good[i-1]++;

            double ans = prob(good,bad,d-1);

            good[i]++;
            good[i-1]--;

            for(int j = 0; j < good[i]; j++) {
                probs.push_back(ans);
            }
        }
    }

    for(int i = 1; i < 7; i++) {
        if(bad[i] > 0) {
            bad[i]--;
            bad[i-1]++;

            double ans = prob(good,bad,d-1);

            bad[i]++;
            bad[i-1]--;

            for(int j = 0; j < bad[i]; j++) {
                probs.push_back(ans);
            }
        }
    }

    double ans = 0;
    for(auto i : probs) {
        ans += i / probs.size();
    }

    memo[{good,bad,d}] = ans;
    return ans;
}

int main() {
    int n, m, d;
    cin >> n >> m >> d;

    vector<int> good(7);
    vector<int> bad(7);

    for(int i = 0; i < n; i++) {
        int t; cin >> t;
        good[t]++;
    }
    for(int i = 0; i < m; i++) {
        int t; cin >> t;
        bad[t]++;
    }

    cout << fixed;
    cout.precision(8);
    cout << prob(good,bad,d) << endl;
}
