#include <iostream>
#include <vector>

using namespace std;

void knock(vector<vector<int>>& adj, vector<bool>& visited, int k) {
    if(visited[k]) {
        return;
    }
    visited[k] = true;

    for(auto i : adj[k]) {
        knock(adj, visited, i);
    }
}

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        int n, m, l;
        cin >> n >> m >> l;

        // Take in input
        vector<vector<int>> adj(n);
        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            adj[a].push_back(b);
        }

        // Count how many can be knocked over
        vector<bool> visited(n, false);
        for(int i = 0; i < l; i++) {
            int k;
            cin >> k;
            k--;
            knock(adj, visited, k);
        }

        // Print the total number knocked over
        int count = 0;
        for(auto i : visited) {
            if(i) {
                count++;
            }
        }
        cout << count << endl;
    }
}
