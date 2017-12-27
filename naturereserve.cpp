#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll cases;
    cin >> cases;

    while(cases--) {
        ll n, m, l, s;
        cin >> n >> m >> l >> s;

        vector<bool> visited(n);
        vector<ll> initial;

        for(ll i = 0; i < s; i++) {
            ll n1;
            cin >> n1;
            n1--;

            visited[n1] = true;
            initial.push_back(n1);
        }

        vector<vector<pair<ll,ll>>> adj(n);
        for(ll i = 0; i < m; i++) {
            ll n1, n2, w;
            cin >> n1 >> n2 >> w;
            n1--;
            n2--;
            adj[n1].push_back({w+l, n2});
            adj[n2].push_back({w+l, n1});
        }

        priority_queue<pair<ll,int>,
                       vector<pair<ll,ll>>,
                       greater<pair<ll,ll>>> q;

        for(auto i : initial) {
            for(auto j : adj[i]) {
                q.push(j);
            }
        }

        ll total = 0;

        while(!q.empty()) {
            ll curr = q.top().second;
            ll dist = q.top().first;
            q.pop();

            if(visited[curr]) {
                continue;
            }
            visited[curr] = true;

            total += dist;

            for(auto i : adj[curr]) {
                q.push(i);
            }
        }

        cout << total << endl;
    }
}
