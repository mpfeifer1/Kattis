#include <bits/stdc++.h>

using namespace std;

int find(vector<int>& d, int a) {
    if(d[a] < 0) return a;
    return d[a] = find(d, d[a]);
}

void join(vector<int>& d, int a, int b) {
    a = find(d, a);
    b = find(d, b);
    if(a == b) return;
    d[a] += d[b];
    d[b] = a;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> d(n, -1);
    vector<pair<int,int>> edges;

    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        n1--; n2--;

        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
        edges.push_back({n1,n2});
    }

    for(int i = 0; i < n; i++) {
        for(int j = 1; j < adj[i].size(); j++) {
            join(d, adj[i][j-1], adj[i][j]);
        }
    }

    bool odd = false;
    for(int i = 0; i < n; i++) {
        if(d[i] < 0) {
            for(auto j : adj[i]) {
                if(find(d,i) == find(d,j)) {
                    odd = true;
                }
            }
        }
    }

    for(auto i : edges) {
        join(d,i.first,i.second);
    }

    int components = 0;
    for(int i = 0; i < n; i++) {
        if(d[i] < 0) components++;
    }

    components--;
    if(!odd) components++;

    cout << components << endl;
}
