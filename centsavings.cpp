#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = (ll)1 << 60;

ll rd(ll n) {
    ll left = n % 10;
    if(left >= 5) {
        return n + (10 - left);
    }
    return n - left;
}

int main() {
    ll n, m;
    cin >> n >> m;

    vector<ll> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    // memo[idx][divider] = cost;
    vector<vector<ll>> memo;
    memo.resize(n+1,vector<ll>(m+1,inf));

    // Base case
    for(ll i = 0; i <= m; i++) {
        memo[0][i] = 0;
    }
    for(ll i = 1; i <= n; i++) {
        memo[i][0] = memo[i-1][0] + v[i-1];
    }

    // Recurrence
    for(ll i = 1; i <= n; i++) {
        for(ll j = m; j > 0; j--) {
            memo[i][j] = min(memo[i-1][j] + v[i-1], rd(memo[i-1][j-1] + v[i-1]));
        }
    }

    // Extract answer
    ll ans = inf;
    for(ll i = 0; i <= m; i++) {
        ans = min(ans,rd(memo[n][i]));
    }

    // Debugging
    /*
    for(ll i = 0; i <= n; i++) {
        for(ll j = m; j >= 0; j--) {
            cout << memo[i][j] << " ";
        }
        cout << endl;
    }
    */

    cout << ans << endl;
}
