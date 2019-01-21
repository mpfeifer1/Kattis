#include <bits/stdc++.h>

using namespace std;
typedef long double ld;

int main() {
    int n, s, k;
    cin >> n >> s >> k;

    // dp[throws][unique] = probability
    vector<vector<ld>> dp;
    dp.resize(n+1,vector<ld>(s+1,0));
    dp[0][0] = 1;

    // Do some DP here
    // For each number of throws
    for(int i = 1; i <= n; i++) {
        // For each count of unique sides afterwards
        for(int j = 1; j <= s; j++) {
            ld probnew = ld(s-(j-1)) / s;
            ld probold = ld(j) / s;
            ld waysnew = probnew * dp[i-1][j-1];
            ld waysold = probold * dp[i-1][j];
            dp[i][j] = waysnew + waysold;
        }
    }

    // Recover answer
    ld prob = 0;
    for(int i = k; i <= s; i++) {
        prob += dp[n][i];
    }
    cout << fixed;
    cout.precision(9);
    cout << prob << endl;
}
