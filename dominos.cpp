#include <bits/stdc++.h>

using namespace std;

int find(vector<int>& d, int a) {
    if(d[a] == -1) {
        return a;
    }

    d[a] = find(d, d[a]);
    return d[a];
}

void join(vector<int>& d, int a, int b) {
    a = find(d, a);
    b = find(d, b);

    if(a == b) {
        return;
    }

    d[a] = b;
}

void dfs1(vector<vector<int>>& adj, unordered_set<int>& vis, stack<int>& r, int curr) {
    vis.insert(curr);
    for(auto i : adj[curr]) {
        if(vis.count(i) == 0) {
            vis.insert(i);
            dfs1(adj, vis, r, i);
        }
    }

    r.push(curr);
}

void dfs2(vector<vector<int>>& adj, unordered_set<int>& vis, stack<int>& r, vector<int>& dis, int curr) {
    for(auto i : adj[curr]) {
        if(vis.count(i) == 0) {
            join(dis, curr, i);
            vis.insert(i);
            dfs2(adj, vis, r, dis, i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;

    while(cases--) {
        // Take in input
        int n, m;
        cin >> n >> m;

        // Build graph
        vector<vector<int>> adj1(n);
        vector<vector<int>> adj2(n);
        vector<pair<int, int>> edges;
        for(int i = 0; i < m; i++) {
            int n1, n2;
            cin >> n1 >> n2;
            n1--;
            n2--;
            adj1[n1].push_back(n2);
            adj2[n2].push_back(n1);
            edges.push_back({n1, n2});
        }

        // First pass
        unordered_set<int> vis;
        stack<int> recent;
        for(int i = 0; i < n; i++) {
            if(vis.count(i) > 0) {
                continue;
            }

            // DFS
            dfs1(adj1, vis, recent, i);
        }

        // Set up metagraph
        vector<int> dis(n, -1);
        unordered_map<int, int> deg;

        // Second pass
        vis.clear();
        while(!recent.empty()) {
            int curr = recent.top();
            recent.pop();
            vis.insert(curr);

            dfs2(adj2, vis, recent, dis, curr);
        }

        // Build "Metagraph"
        for(int i = 0; i < dis.size(); i++) {
            deg[find(dis, i)] = 0;
        }

        // Find degrees
        for(auto i : edges) {
            if(find(dis, i.first) != find(dis, i.second)) {
                deg[find(dis, i.second)]++;
            }
        }

        // Find degree 0
        int total = 0;
        for(auto i : deg) {
            if(i.second == 0) {
                total++;
            }
        }

        // Print answer
        cout << total << endl;
    }
}
