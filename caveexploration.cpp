#include <bits/stdc++.h>

using namespace std;
typedef vector<vector<int>> graph;
typedef vector<pair<int,int>> vpii;
typedef vector<bool> vb;
typedef vector<int> vi;

int dfstime = 0;

void find(graph& adj, vpii& bridges, vb& vis, vi& par, vi& hi, vi& lo, int curr) {
    vis[curr] = true;
    hi[curr] = lo[curr] = ++dfstime;
    for(auto next : adj[curr]) {
        if(!vis[next]) {
            par[next] = curr;
            find(adj, bridges, vis, par, hi, lo, next);
            lo[curr] = min(lo[curr], lo[next]);
            if(lo[next] > hi[curr]) {
                bridges.push_back({next,curr});
            }
        }
        else if(next != par[curr]) {
            lo[curr] = min(lo[curr], hi[next]);
        }
    }
}

int dfs(graph& adj, vb& vis, set<pair<int,int>>& skip, int curr) {
    vis[curr] = true;
    int total = 1;
    for(auto next : adj[curr]) {
        if(vis[next]) {
            continue;
        }
        if(skip.count({curr,next}) || skip.count({next,curr})) {
            continue;
        }
        total += dfs(adj, vis, skip, next);
    }
    return total;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Read in graph
    graph adj(n);
    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    // Allocate memory
    vpii bridges;
    vb vis(n,false);
    vi par(n,-1);
    vi hi(n,-1);
    vi lo(n,-1);

    // Find bridges
    find(adj, bridges, vis, par, hi, lo, 0);

    // Put bridges in a better data structure
    set<pair<int,int>> skip;
    for(auto i : bridges) {
        skip.insert(i);
    }

    // Reset memory
    for(int i = 0; i < n; i++) {
        vis[i] = false;
    }

    // See how many nodes can be reaced without using bridges
    cout << dfs(adj, vis, skip, 0) << endl;
}
