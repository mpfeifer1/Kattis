#include <bits/stdc++.h>

using namespace std;

struct edge {
    int u,v,w;
};

bool cmp(const edge &i, const edge &j) {
    return i.w < j.w;
}

void solve(int n, int m) {
    vector<edge> edges(m);
    map<pair<int, int>, int> toWeight;
    for(int i = 0; i < m; ++i) {
        int u,v,w;
        cin >> u >> v >> w;
        edges[i] = {u,v,w};
        if(u > v) swap(u,v);
        toWeight[{u,v}] = w;
    }
    sort(edges.begin(), edges.end(), cmp);
    vector<set<int>> adj(n);
    int res = 1e9;
    multiset<int> weights;
    for(int i = 0; i < m; ++i) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        queue<pair<int, int>> q;
        q.push({u,u});
        bool cycle = false;
        vector<int> parent(n);
        while(!q.empty()) {
            int node = q.front().first;
            int par = q.front().second;
            parent[node] = par;
            if(node == v) {
                cycle = true;
                break;
            }
            q.pop();
            for(int to : adj[node]) {
                if(to == par) continue;
                q.push({to, node});
            }
        }
        if(!cycle) {
            adj[u].insert(v);
            adj[v].insert(u);
            weights.insert(w);
            if(weights.size() == n-1) {
                res = min(res, (*weights.rbegin()) - (*weights.begin()));
            }
            continue;
        }
        int curr = v;
        int minEdge = 1e9;
        int minU, minV;
        while(parent[curr] != curr) {
            int currWeight = toWeight[{min(parent[curr], curr), max(parent[curr], curr)}];
            if(minEdge > currWeight) {
                minEdge = currWeight;
                minU = parent[curr];
                minV = curr;
            }
            curr = parent[curr];
        }
        adj[minU].erase(minV);
        adj[minV].erase(minU);
        adj[u].insert(v);
        adj[v].insert(u);
        weights.erase(weights.find(minEdge));
        weights.insert(w);
        if(weights.size() == n-1) {
            res = min(res, (*weights.rbegin()) - (*weights.begin()));
        }
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    while(cin >> n && n > 0) {
        int m;
        cin >> m;
        solve(n, m);
    }
}
