#include <bits/stdc++.h>

using namespace std;

int LOG = 19;
int n, m, k;

vector<pair<int,int>> ans;

// Calculate depth for all nodes
vector<int> order;
int currorder = 0;
void dfs_lca(vector<vector<int>>& adj, vector<int>& depth, vector<bool>& vis, vector<int>& par, int node, int Depth = 0) {
    depth[node] = Depth;
    vis[node] = true;
    order[node] = currorder;
    currorder++;
    for(int x : adj[node]) {
        if(!vis[x]) {
            par[x] = node;
            dfs_lca(adj, depth, vis, par, x, Depth+1);
        }
    }
}

bool cmp(int& i1, int& i2) {
    return order[i1] < order[i2];
}

// Return Nth parent of node x
int parent(vector<vector<int>>& memo, int x, int n) {
    for(int k = LOG; k >= 0; --k) {
        if(n & (1 << k)) {
            x = memo[x][k];
            if(x == -1) return x;
        }
    }
    return x;
}

// Returns lowest common ancestor of x and y
int lca(vector<vector<int>>& memo, vector<int>& depth, vector<int>& par, int x, int y) {
    if(depth[x] < depth[y]) swap(x,y);
    int diff = depth[x] - depth[y];
    for(int k = LOG; k >= 0; --k) {
        if(diff&(1<<k)) {
            x = memo[x][k];
        }
    }
    for(int k = LOG; k >= 0; --k) {
        if(memo[x][k] != memo[y][k]) {
            x = memo[x][k];
            y = memo[y][k];
        }
    }
    if(x != y) x = par[x];
    return x;
}

// Builds LCA table
void build(vector<vector<int>>& memo, vector<int>& par) {
    int n = par.size();
    for(int i = 0; i < n; ++i) memo[i][0] = par[i];
    for(int k = 1; k < LOG; ++k) {
        for(int i = 0; i < n; ++i) {
            if(memo[i][k-1] == -1) {
                memo[i][k] = -1;
                continue;
            }
            memo[i][k] = memo[memo[i][k-1]][k-1];
        }
    }
}

int dfs(vector<vector<int>>& adj, vector<bool>& vis, vector<int>& delta, int curr) {
    // DFS and process children first
    vis[curr] = true;
    int total = 0;
    for(auto& next : adj[curr]) {
        if(vis[next]) continue;

        int on = dfs(adj, vis, delta, next);
        total += on;
        if(on >= k) {
            ans.push_back({curr,next});
        }
    }

    // Add in our delta here
    total += delta[curr];
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // Grab input, allocate memory
    cin >> n >> m >> k;
    vector<vector<int>> adj(n);
    map<pair<int,int>, int> conv;

    // Read in edges
    for(int i = 0; i < n-1; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        n1--; n2--;

        adj[n1].push_back(n2);
        adj[n2].push_back(n1);

        if(n2 > n1) {
            swap(n1, n2);
        }

        conv[{n1,n2}] = i+1;
    }

    int root = 0;

    // Build LCA Table
    vector<int> depth(n);
    vector<bool> vis(n, false);
    vector<int> par(n);
    par[root] = root;
    vector<vector<int>> memo(n, vector<int>(LOG, -1));
    order.resize(n);

    // Build LCA table
    dfs_lca(adj, depth, vis, par, root);
    build(memo, par);

    // Read in people, convert to operations
    vector<int> delta(n,0);
    for(int i = 0; i < m; i++) {
        // Get memory for this person's nodes
        int t;
        cin >> t;
        vector<int> v(t);

        // The person turns 'on' everywhere they state
        for(auto& val : v) {
            cin >> val;
            val--;
            delta[val]++;
        }

        // Sort this person's nodes by DFS order
        sort(v.begin(), v.end(), cmp);

        // The person turns 'off' at the lca each pair of nodes
        for(int i = 1; i < v.size(); i++) {
            int anc = lca(memo, depth, par, v[i-1], v[i]);
            delta[anc]--;
        }
        int anc = lca(memo, depth, par, v.front(), v.back());
        delta[anc]--;
    }

    // Run DFS to calculate edges
    vis.clear();
    vis.resize(n,false);
    dfs(adj, vis, delta, root);

    // For each edge, get edge number
    vector<int> vals;
    for(auto& i : ans) {
        if(i.first < i.second) {
            swap(i.first, i.second);
        }
        vals.push_back(conv[i]);
    }

    // Sort edge numbers
    sort(vals.begin(), vals.end());

    // Print answer
    cout << vals.size() << endl;
    for(auto& i : vals) {
        cout << i << " ";
    }
    cout << endl;
}
