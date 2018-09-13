#include <bits/stdc++.h>

using namespace std;

pair<int,vector<vector<int>>> buildrows(int n) {
    vector<int> lens;
    for(int i = 0; i <= n-1; i++) {
        lens.push_back(n+i);
    }
    for(int i = n-2; i >= 0; i--) {
        lens.push_back(n+i);
    }

    vector<vector<int>> actual(lens.size());

    int t = 0;
    for(int i = 0; i < lens.size(); i++) {
        for(int j = 0; j < lens[i]; j++) {
            actual[i].push_back(t);
            t++;
        }
    }

    return {t,actual};
}

int main() {
    int r, n, start, end, m;
    cin >> r >> n >> start >> end >> m;

    // Build rows, count total squares
    pair<int,vector<vector<int>>> p = buildrows(r);
    int total = p.first;
    vector<vector<int>> idx = p.second;

    // Build Adjacency
    vector<vector<int>> adj(total);
    vector<pair<int,int>> edges;

    // Join across
    for(auto list : idx) {
        for(int i = 1; i < list.size(); i++) {
            edges.push_back({list[i],list[i-1]});
        }
    }

    // Join up (top half)
    for(int i = 1; i < r; i++) {
        // join first straight up
        edges.push_back({idx[i][0], idx[i-1][0]});

        // join others left and up
        for(int j = 1; j < idx[i].size(); j++) {
            if(j != idx[i].size()-1) {
                edges.push_back({idx[i][j], idx[i-1][j]});
            }
            edges.push_back({idx[i][j], idx[i-1][j-1]});
        }
    }

    // Join up (bottom half)
    for(int i = r; i < 2*r-1; i++) {
        // join all right and up
        for(int j = 0; j < idx[i].size(); j++) {
            edges.push_back({idx[i][j], idx[i-1][j]});
            edges.push_back({idx[i][j], idx[i-1][j+1]});
        }
    }

    for(auto i : edges) {
        adj[i.first].push_back(i.second);
        adj[i.second].push_back(i.first);
    }

    // Make sure start and end are correct
    start--; end--;

    // Build visited
    vector<bool> vis(total, false);
    vector<int> dist(total, 1000000);

    // Mark used squares
    for(int i = 0; i < m; i++) {
        int t;
        cin >> t;
        t--;
        vis[t] = true;
    }

    queue<int> q;
    q.push(start);
    dist[start] = 0;
    vis[start] = true;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(auto next : adj[curr]) {
            if(!vis[next]) {
                vis[next] = true;
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }

    if(dist[end] <= n) {
        cout << dist[end] << endl;
    }
    else {
        cout << "No" << endl;
    }
}
