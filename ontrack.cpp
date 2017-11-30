#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll best = 0;
ll node = 0;
ll after = 0;

ll n;

ll count(vector<ll>& counts) {
    if(counts.size() == 0) {
        return 0;
    }

    ll left = n;
    ll total = 0;

    for(auto i : counts) {
        left -= i;
        total += i * left;
    }

    return total;
}

ll dfs(vector<vector<ll>>& adj, vector<bool>& vis, ll curr) {
    vis[curr] = true;

    // Get all counts
    vector<ll> counts;
    ll total = 0;
    for(auto i : adj[curr]) {
        if(!vis[i]) {
            counts.push_back(dfs(adj, vis, i));
            total += counts.back();
        }
    }
    counts.push_back(n - total);

    // Find the values here
    if(counts.size() > 0) {
        ll besthere = count(counts);

        if(besthere > best) {
            best = besthere;
            node = curr;

            sort(counts.begin(), counts.end());

            ll back = counts.back();
            counts.pop_back();
            counts.back() += back;

            after = count(counts);
        }
    }

    // Return size of this subtree
    return total + 1;
}

int main() {
    cin >> n;

    vector<vector<ll>> adj(n+1);

    for(ll i = 0; i < n; i++) {
        ll n1, n2;
        cin >> n1 >> n2;

        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    vector<bool> vis(n+1, false);

    dfs(adj, vis, 0);

    cout << best << " " << after << endl;
}
