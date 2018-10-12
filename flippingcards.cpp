#include <bits/stdc++.h>

using namespace std;

bool match(int curr, vector<vector<int>>& adj, vector<int>& l, vector<int>& r, vector<int>& vis) {
    if(vis[curr]) return false;
    vis[curr] = true;

    for(auto next : adj[curr]) {
        if(r[next] == -1 || match(r[next], adj, l, r, vis)) {
            l[curr] = next;
            r[next] = curr;
            return true;
        }
    }
    return false;
}

int bipartite(vector<vector<int>>& adj, int n, int m) {
    vector<int> l, r, vis;
    l.resize(n, -1);
    r.resize(m, -1);
    vis.resize(n);

    bool works = true;
    while(works) {
        works = false;
        fill(vis.begin(), vis.end(), 0);
        for(int i = 0; i < n; i++) {
            if(l[i] == -1) {
                works |= match(i, adj, l, r, vis);
            }
        }
    }

    int ret = 0;
    for(int i = 0; i < n; i++) {
        ret += (l[i] != -1);
    }
    return ret;
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    for(int i = 0; i < n; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        n1--; n2--;
        adj[i].push_back(n1);
        adj[i].push_back(n2);
    }

    int best = bipartite(adj, n, 2*n);

    if(best == n) {
        cout << "possible" << endl;
    }
    else {
        cout << "impossible" << endl;
    }
}

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        solve();
    }
}
