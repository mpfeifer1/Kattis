#include <bits/stdc++.h>

using namespace std;

void solve(vector<vector<bool>>& memo, vector<vector<int>>& adj, int n, int m) {
    // Get list of degrees
    vector<int> deg(n, 0);
    for(auto i : adj) {
        for(auto j : i) {
            deg[j]++;
        }
    }

    // Initialzie Toposort
    queue<int> zeroin;
    zeroin.push(0);
    memo[0][0] = true;

    // Toposort, filling in memo table
    while(!zeroin.empty()) {
        int curr = zeroin.front();
        zeroin.pop();

        for(auto i : adj[curr]) {
            for(int j = 0; j < m; j++) {
                if(memo[curr][j]) {
                    memo[i][j+1] = true;
                }
            }
            deg[i]--;
            if(deg[i] == 0) {
                zeroin.push(i);
            }
        }
    }
}

int main() {
    // Read in data
    int n1, n2, m1, m2;
    cin >> n1 >> n2 >> m1 >> m2;

    // Set up storage
    vector<vector<int>> adj1(n1);
    vector<vector<int>> adj2(n2);

    // Read in adjacency list 2
    for(int i = 0; i < m1; i++) {
        int t1, t2;
        cin >> t1 >> t2;

        t1--;
        t2--;

        adj1[t1].push_back(t2);
    }

    // Read in adjacency list 1
    for(int i = 0; i < m2; i++) {
        int t1, t2;
        cin >> t1 >> t2;

        t1--;
        t2--;

        adj2[t1].push_back(t2);
    }

    // Set up memoization
    vector<vector<bool>> memo1;
    vector<vector<bool>> memo2;
    memo1.resize(n1, vector<bool>(m1, false));
    memo2.resize(n2, vector<bool>(m2, false));

    // Solve
    solve(memo1, adj1, n1, m1);
    solve(memo2, adj2, n2, m2);

    // Combine all step patterns
    unordered_set<int> s;
    for(int i = 0; i < m1+1; i++) {
        for(int j = 0; j < m2+1; j++) {
            if(memo1[n1-1][i] && memo2[n2-1][j]) {
                s.insert(i+j);
            }
        }
    }

    // Process queries
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if(s.count(t) > 0) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}
