#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = (ll)1 << 60;

void calc(vector<vector<int>>& adj, vector<ll>& cost, vector<vector<ll>>& dp, int curr) {
    // Base Case
    if(adj[curr].size() == 0) {
        // theres no way this is right
        dp[curr][0] = cost[curr];
        dp[curr][1] = 0;
        dp[curr][2] = cost[curr];
        return;
    }

    // Recursively call children
    for(auto next : adj[curr]) {
        calc(adj, cost, dp, next);
    }

    // Case 0 (bribe this guy)
    ll cost0 = cost[curr];
    for(auto next : adj[curr]) {
        cost0 += dp[next][1];
    }
    dp[curr][0] = cost0;

    // Case 1 (bribe parent)
    ll cost1 = 0;
    for(auto next : adj[curr]) {
        cost1 += min(dp[next][0], dp[next][2]);
    }
    dp[curr][1] = cost1;

    // Case 2 (bribe double-parent)
    ll cost2 = inf;
    for(auto next : adj[curr]) {
        ll costhere = cost1 - min(dp[next][0], dp[next][2]);
        costhere += dp[next][0];
        cost2 = min(cost2, costhere);
    }
    dp[curr][2] = cost2;
}

int main() {
    int n;
    cin >> n;

    vector<ll> cost(n);
    vector<int> deg(n, 0);
    vector<vector<int>> adj(n);
    vector<vector<ll>> dp(n, vector<ll>(3, inf));

    for(int i = 0; i < n; i++) {
        cin >> cost[i];
        int t;
        cin >> t;
        for(int j = 0; j < t; j++) {
            int n1;
            cin >> n1;
            deg[n1]++;
            adj[i].push_back(n1);
        }
    }

    int root = 0;
    for(int i = 0; i < n; i++) {
        if(deg[i] == 0) {
            root = i;
        }
    }

    calc(adj, cost, dp, root);

    cout << min(dp[root][0], dp[root][2]) << endl;
}
