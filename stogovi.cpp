#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > adj, memo;
vector<int> depth, parent, conv;
vector<bool> visited;

int LOG = 21;

// Calculate depth for all nodes
void dfs(int node, int Depth = 0) {
    depth[node] = Depth;
    for(int x : adj[node]) {
        dfs(x, Depth+1);
    }
}

// Find LCA of two nodes (O(log(n))
int lca(int x, int y) {
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
    if(x != y) x = parent[x];
    return x;
}

// Define query struct
struct query {
    char c;
    int v, w;
};

int main() {
    // Fast IO
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    // Read in N
    int n;
    cin >> n;

    // Allocate storage
    // One based labeling for nodes.
    adj.resize(n+1);
    conv.resize(n+1);
    depth.resize(n+1);
    parent.resize(n+1);
    vector<query> queries(n+1);

    // Read in all connections
    for(int i = 1; i <= n; ++i) {
        // Read in type
        char c;
        cin >> c;
        queries[i].c = c;

        // Read in first number
        int v;
        cin >> v;
        v = conv[v];
        queries[i].v = v;

        if(c == 'a') {
            // Create new node
            parent[i] = v;
            adj[v].push_back(i);

            // Set this node to be itself
            conv[i] = i;
        }

        if(c == 'b') {
            // Set this node to be the parent of the node
            conv[i] = parent[v];
        }

        if(c == 'c') {
            // Read in compare node
            int w;
            cin >> w;
            w = conv[w];
            queries[i].w = w;

            // Set this node to be the node
            conv[i] = v;
        }
    }

    // DFS
    parent[0] = 0;
    dfs(0);

    // Calculate LCA table
    memo.resize(n+1, vector<int>(LOG+1,0));
    for(int i = 1; i <= n; ++i) memo[i][0] = parent[i];
    for(int k = 1; k <= LOG; ++k) {
        for(int i = 1; i <= n; ++i) {
            memo[i][k] = memo[memo[i][k-1]][k-1];
        }
    }

    // Run through all queries and print answers
    for(int i = 1; i <= n; i++) {
        int c = queries[i].c;
        int v = queries[i].v;
        int w = queries[i].w;

        if(c == 'b') {
            cout << v << endl;
        }

        if(c == 'c') {
            int node = lca(v, w);
            cout << depth[conv[node]] << endl;
        }
    }

    return 0;
}
