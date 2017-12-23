#include <bits/stdc++.h>

using namespace std;
typedef long double ld;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while(cin >> n >> m) {
        if(n == 0 && m == 0) {
            break;
        }

        vector<vector<pair<ld, int>>> adj(n);
        for(int i = 0; i < m; i++) {
            int n1, n2;
            ld w;
            cin >> n1 >> n2 >> w;
            adj[n1].push_back({w, n2});
            adj[n2].push_back({w, n1});
        }

        vector<bool> vis(n, false);
        vector<ld> dist(n, 0);

        priority_queue<pair<ld,int>> pq;
        pq.push({1,0});

        while(!pq.empty()) {
            int curr = pq.top().second;
            ld size = pq.top().first;
            pq.pop();

            if(vis[curr]) {
                continue;
            }
            vis[curr] = true;

            dist[curr] = size;

            for(auto i : adj[curr]) {
                int next = i.second;
                ld fact = i.first;
                pq.push({size * fact, next});
            }
        }

        cout << fixed;
        cout.precision(4);
        cout << dist[n-1] << endl;
    }
}
