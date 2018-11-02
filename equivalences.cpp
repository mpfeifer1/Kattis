#include <bits/stdc++.h>

using namespace std;

template <class T>
int find(T& d, int a) {
    if(d[a] == -1) return a;
    return d[a] = find(d, d[a]);
}

template <class T>
void join(T& d, int a, int b) {
    a = find(d, a);
    b = find(d, b);
    if(a == b) return;
    d[a] = b;
}

void dfs1(vector<vector<int>>& adj, unordered_set<int>& vis, stack<int>& r, int curr) {
    vis.insert(curr);
    for(auto i : adj[curr]) {
        if(vis.count(i) == 0) {
            dfs1(adj, vis, r, i);
        }
    }
    r.push(curr);
}

void dfs2(vector<vector<int>>& adj, unordered_set<int>& vis, vector<int>& dis, int curr) {
    vis.insert(curr);
    for(auto i : adj[curr]) {
        if(vis.count(i) == 0) {
            join(dis, curr, i);
            vis.insert(i);
            dfs2(adj, vis, dis, i);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    // Read in input
    vector<vector<int>> adj1(n);
    vector<vector<int>> adj2(n);
    vector<pair<int,int>> input(m);
    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        n1--; n2--;
        adj1[n1].push_back(n2);
        adj2[n2].push_back(n1);
        input[i] = {n1,n2};
    }

    vector<int> d(n, -1);
    unordered_set<int> vis;
    stack<int> r;

    // Run DFS to get SCC IDs
    for(int i = 0; i < n; i++) {
        if(vis.count(i) == 0) {
            dfs1(adj1,vis,r,i);
        }
    }
    vis.clear();
    while(r.size() > 0) {
        int curr = r.top();
        r.pop();
        if(vis.count(curr) == 0) {
            dfs2(adj2,vis,d,curr);
        }
    }

    // Find the names of the actual nodes
    vector<int> nodes;
    for(int i = 0; i < n; i++) {
        if(d[i] == -1) {
            nodes.push_back(i);
        }
    }

    // Reserve the space for the metagraph
    unordered_map<int,unordered_set<int>> meta_adj;
    unordered_map<int,int> indeg, outdeg;
    unordered_map<int,int> cc;
    meta_adj.reserve(nodes.size());
    outdeg.reserve(nodes.size());
    indeg.reserve(nodes.size());
    cc.reserve(nodes.size());

    // Start all degrees at 0, and nothing joined
    for(auto& i : nodes) {
        outdeg[i] = 0;
        indeg[i] = 0;
        cc[i] = -1;
    }

    // Loop over edges, and add degree counts
    for(auto& i : input) {
        int n1 = find(d, i.first);
        int n2 = find(d, i.second);
        if(n1 == n2) continue;
        meta_adj[n1].insert(n2);
        outdeg[n1]++;
        indeg[n2]++;
        join(cc, n1, n2);
    }

    // Keep track of the total degrees for each CC in the metagraph
    unordered_map<int, pair<int,int>> totaldeg;

    // Start each pait at 0,0
    for(auto i : nodes) {
        totaldeg[find(cc,i)] = {0,0};
    }

    // For each CC, count how many nodes with indegree 0 and outdegree 0
    for(auto i : nodes) {
        if(indeg[i] == 0) {
            totaldeg[find(cc,i)].first++;
        }
        if(outdeg[i] == 0) {
            totaldeg[find(cc,i)].second++;
        }
    }

    // Save the indegrees and outdegrees for each CC
    vector<pair<int,int>> ans;
    for(auto i : totaldeg) {
        ans.push_back({i.second.first, i.second.second});
    }

    // If there's only 1 CC, and it's 1/1, answer is 0
    if((ans.size() <= 1) && (ans[0] == pair<int,int>(1,1))) {
        cout << 0 << endl;
        return;
    }

    // Loop through each CC and find answer
    int in = 0, out = 0;
    for(auto i : ans) {
        in += i.first;
        out += i.second;
    }

    cout << max(in,out) << endl;
}

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        solve();
    }
}
