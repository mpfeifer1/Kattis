#include <unordered_map>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int find(vector<int>& disjoint, int n) {
    if(disjoint[n] == -1) {
        return n;
    }

    disjoint[n] = find(disjoint, disjoint[n]);
    return disjoint[n];
}

void join(vector<int>& disjoint, int a, int b) {
    a = find(disjoint, a);
    b = find(disjoint, b);

    if(a == b) {
        return;
    }

    disjoint[a] = b;
}

bool bfs(vector<vector<int>>& adj, vector<int>& visited, int start) {
    queue<pair<int, int>> q;
    q.push({start, 0});

    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        visited[p.first] = p.second;
        for(auto i : adj[p.first]) {
            if(visited[i] == p.second) {
                return false;
            }
            if(visited[i] == -1) {
                q.push({i, (p.second + 1)%2});
            }
        }
    }
    return true;
}

int main() {
    // Take in input
    int n;
    cin >> n;
    vector<string> inttostr;
    unordered_map<string, int> strtoint;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        inttostr.push_back(s);
        strtoint[s] = i;
    }

    // Build necessary data structures
    vector<int> disjoint;
    disjoint.resize(n, -1);
    vector<vector<int>> adj;
    adj.resize(n);

    // Add items to disjoint set and adjacency list
    int c;
    cin >> c;
    for(int i = 0; i < c; i++) {
        string a, b;
        cin >> a >> b;
        int a1, b1;
        a1 = strtoint[a];
        b1 = strtoint[b];

        join(disjoint, a1, b1);
        adj[a1].push_back(b1);
        adj[b1].push_back(a1);
    }

    // Break into clusters of items
    unordered_map<int, vector<int>> items;
    for(int i = 0; i < disjoint.size(); i++) {
        items[find(disjoint, i)].push_back(i);
    }

    // For each cluster of items, run a BFS to see if it is OK
    vector<int> visited;
    visited.resize(n, -1);
    bool works = true;
    for(auto cluster : items) {
        works &= bfs(adj, visited, cluster.second[0]);
    }

    // Print the result
    if(!works) {
        cout << "impossible" << endl;
    }
    else {
        for(int i = 0; i < visited.size(); i++) {
            if(visited[i] == 0) {
                cout << inttostr[i] << " ";
            }
        }
        cout <<endl;
        for(int i = 0; i < visited.size(); i++) {
            if(visited[i] == 1) {
                cout << inttostr[i] << " ";
            }
        }
        cout <<endl;
    }
}
