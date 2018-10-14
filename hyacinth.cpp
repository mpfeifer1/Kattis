#include <bits/stdc++.h>

using namespace std;

int currfreq = 1;
void dfs(vector<vector<int>>& adj, vector<pair<int,int>>& freq, int curr, int prev, int root) {
    int children = 0;
    for(auto next : adj[curr]) {
        if(next != prev) {
            children++;
        }
    }

    // If root node, assign two new vals
    if(curr == root) {
        freq[curr].first = currfreq++;
        freq[curr].second = currfreq++;
    }

    else {
        // If a leaf, copy the parents
        if(children == 0) {
            freq[curr].first = freq[prev].first;
            freq[curr].second = freq[prev].second;
        }

        // If not a leaf, copy parent's second into our first, assign a new second
        else {
            freq[curr].first = freq[prev].second;
            freq[curr].second = currfreq++;
        }
    }


    for(auto next : adj[curr]) {
        if(next != prev) {
            dfs(adj, freq, next, curr, root);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> freq(n, {-1,-1});
    vector<vector<int>> adj(n);
    vector<pair<int,int>> input;
    vector<int> deg(n, 0);

    for(int i = 0; i < n-1; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        n1--; n2--;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
        deg[n1]++;
        deg[n2]++;
        input.push_back({n1,n2});
    }

    int root;
    for(int i = 0; i < n; i++) {
        if(deg[i] == 1) {
            root = i;
            break;
        }
    }

    dfs(adj, freq, root, -1, root);

    for(int i = 0; i < n; i++) {
        cout << freq[i].first << " " << freq[i].second << endl;
    }
}
