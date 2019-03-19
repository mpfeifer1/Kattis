#include <bits/stdc++.h>

using namespace std;
#define int long long

/****************** Disjoint Set *************************/
int find(vector<int>& d, int a) {
    if(d[a] == -1) return a;
    return d[a] = find(d,d[a]);
}

// Set B as the representative
void join(vector<int>& d, int a, int b) {
    a = find(d,a);
    b = find(d,b);
    if(a == b) return;
    d[a] = b;
}

/****************** DFS Order *************************/
vector<int> t_in;
vector<int> t_out;
void dfs_order(vector<vector<pair<int,int>>>& adj, int curr, int& time) {
    t_in[curr] = time++;
    for(auto i : adj[curr]) {
        int next = i.first;
        dfs_order(adj,next,time);
    }
    t_out[curr] = time++;
}

int dfs_math(vector<vector<pair<int,int>>>& adjhere, int curr, vector<int>& diff) {
    int ans = 0;
    for(auto i : adjhere[curr]) {
        int next = i.first;
        int weight = i.second;
        ans += dfs_math(adjhere, next, diff);
        ans += weight * abs(diff[next]);
        diff[curr] += diff[next];
    }
    return ans;
}

/****************** Extra *************************/
struct edge {
    int u, v, w;
};

bool cmp(edge& e1, edge& e2) {
    return tie(e1.w,e1.u,e1.v) <
           tie(e2.w,e2.u,e2.v);
}

bool q_cmp(pair<int,int> p1, pair<int,int> p2) {
    return t_in[p1.first] < t_in[p2.first];
}

bool t_cmp(int t1, int t2) {
    return t_in[t1] < t_in[t2];
}

vector<vector<pair<int,int>>> adj;

/****************** LCA *************************/
const int Max = 4e5+3, Log = 20+1;
int memo[Max][Log];
int depth[Max];

void dfs(int node, int prev, int Depth = 0) {
    depth[node] = Depth;
    memo[node][0] = prev;
    for(int i = 1; i < Log; ++i) {
        memo[node][i] = memo[memo[node][i-1]][i-1];
    }
    for(auto t : adj[node]) {
        int to = t.first;
        if(to == prev) continue;
        dfs(to, node, Depth+1);
    }
}

int LCA(int x, int y) {
    if(depth[x] < depth[y]) swap(x,y);
    int diff = depth[x] - depth[y];
    for(int k = Log-1; k >= 0; --k) {
        if(diff&(1<<k)) {
            x = memo[x][k];
        }
    }
    for(int k = Log-1; k >= 0; --k) {
        if(memo[x][k] != memo[y][k]) {
            x = memo[x][k];
            y = memo[y][k];
        }
    }
    if(x != y) x = memo[x][0];
    return x;
}

/****************** Globals *************************/
vector<int> height;

/****************** Queries *************************/

void solvequery() {
    int t;
    cin >> t;

    // Read in the query
    vector<pair<int,int>> query(t);
    for(auto& i : query) {
        cin >> i.first >> i.second;
        i.first--;
    }

    // Sort the query nodes in DFS order
    sort(query.begin(),query.end(),q_cmp);

    // Find all nodes we'll need
    for(int i = 1; i < t; i++) {
        query.push_back({LCA(query[i-1].first,query[i].first),0});
    }
    sort(query.begin(),query.end(),q_cmp);

    // Build the smaller graph using only these nodes
    int roothere = query.front().first;
    stack<int> s;
    s.push(query.front().first);
    vector<vector<pair<int,int>>> adjhere(query.size());
    map<int,int> conv;
    conv[roothere] = 0;
    roothere = 0;
    for(int i = 1; i < query.size(); i++) {
        while(!s.empty()) {
            if(t_out[s.top()] > t_in[query[i].first]) break;
            s.pop();
        }
        int u = s.top();
        int v = query[i].first;

        if(!conv.count(u)) {
            int t = conv.size();
            conv[u] = t;
        }
        if(!conv.count(v)) {
            int t = conv.size();
            conv[v] = t;
        }

        adjhere[conv[u]].push_back({conv[v],height[u]-height[v]});

        s.push(query[i].first);
    }

    // Run a DFS, and count how many times each edge is traversed
    vector<int> diff(query.size(),0);
    for(auto i : query) {
        diff[conv[i.first]] = i.second;
    }
    int ans = dfs_math(adjhere, roothere, diff) / 2;

    // Print answer
    cout << ans << endl;
}

/****************** Preprocessing *************************/
void solve() {
    int n;
    cin >> n;

    // Read in all the edges
    vector<edge> edges(n-1);
    for(auto& i : edges) {
        cin >> i.u >> i.v >> i.w;
        i.u--; i.v--;
    }

    // Prepare to build big graph
    height.resize(2*n,0);  // Store the height of each node
    adj.resize(2*n);       // Adjacency list, stores {dest,weight}
    vector<int> d(2*n,-1); // Disjoint set to show what node represents this one
    sort(edges.begin(),edges.end(),cmp);

    // Build big graph
    int currnode = n;
    for(auto i : edges) {
        i.u = find(d,i.u);
        i.v = find(d,i.v);

        height[currnode] = i.w;

        adj[currnode].push_back({i.u,i.w-height[i.u]});
        adj[currnode].push_back({i.v,i.w-height[i.v]});

        join(d,i.u,currnode);
        join(d,i.v,currnode);

        currnode++;
    }
    int root = currnode-1;

    // Get the DFS order
    t_in.resize(n*2);
    t_out.resize(n*2);
    int time = 0;
    dfs_order(adj, root, time);

    // Prepare the LCA array
    dfs(root,root);

    // For each query
    int q;
    cin >> q;
    while(q--) {
        solvequery();
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
