#include <bits/stdc++.h>

using namespace std;

bool cmp(multiset<int>& m1, multiset<int>& m2) {
    return m1.size() > m2.size();
}

void dfs(vector<vector<int>>& adj, vector<int>& val, vector<multiset<int>>& sets, int curr) {
    // Run DFS for all lower sets, keep track of largest
    int biggest = curr;
    for(int i = 0; i < adj[curr].size(); i++) {
        int next = adj[curr][i];
        dfs(adj, val, sets, next);
        if(sets[next].size() > sets[biggest].size()) {
            biggest = next;
        }
    }

    // Set this node's set as the biggest child set
    swap(sets[biggest], sets[curr]);

    // For all child sets, merge into the parent's set
    for(int i = 0; i < adj[curr].size(); i++) {
        int next = adj[curr][i];
        for(auto& j : sets[next]) {
            sets[curr].insert(j);
        }
    }

    // Find this val in our LIS
    auto it = sets[curr].lower_bound(val[curr]);

    // If too big, add to end
    if(it == sets[curr].end()) {
        sets[curr].insert(val[curr]);
    }

    // Otherwise, update a val
    else {
        sets[curr].erase(it);
        sets[curr].insert(val[curr]);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> val(n);
    vector<vector<int>> adj(n);

    for(int i = 0; i < n; i++) {
        cin >> val[i];
        int par;
        cin >> par;
        if(par == 0) continue;
        par--;
        adj[par].push_back(i);
    }

    vector<multiset<int>> sets(n);
    dfs(adj, val, sets, 0);
    cout << sets[0].size() << endl;
}
