#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    string color(n, 'A');
    vector<vector<int>> adj(n);

    for(int i = 0; i < 5; i++) {
        int t;
        cin >> t;
        for(int j = 0; j < t; j++) {
            int n1, n2;
            cin >> n1 >> n2;
            n1--; n2--;
            adj[n1].push_back(n2);
            adj[n2].push_back(n1);
        }
    }

    queue<int> q;
    for(int i = 0; i < n; i++) {
        q.push(i);
    }

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        int match = 0;
        for(auto next : adj[curr]) {
            if(color[next] == color[curr]) match++;
        }

        if(match > 2) {
            color[curr] = color[curr] ^ 'A' ^ 'B';
            for(auto next : adj[curr]) {
                q.push(next);
            }
        }
    }

    cout << color << endl;
}
