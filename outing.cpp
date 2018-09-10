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
    d[b] += d[a];
    d[a] = b;
}

int size(vector<int>& d, int a) {
    a = find(d, a);
    return -d[a];
}

// Returns {node,dist}
pair<int,int> bfs(vector<vector<int>>& adj, int start) {
    map<int,int> dist;

    queue<int> q;
    dist[start] = 0;
    q.push(start);

    int bestdist = 0;
    int bestidx = start;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(auto next : adj[curr]) {
            if(dist.count(next) == 0) {
                dist[next] = dist[curr] + 1;
                if(dist[next] > bestdist) {
                    bestdist = dist[next];
                    bestidx = next;
                }
                q.push(next);
            }
        }
    }

    return {bestidx, bestdist};
}

int findcycle(vector<vector<int>>& adj, int start) {
    pair<int,int> p1 = bfs(adj,start);
    pair<int,int> p2 = bfs(adj, p1.first);
    return 1 + p2.second;
}

void add(vector<bool>& can, pair<int,int> p) {
    vector<int> next(can.size()*2+2, false);

    for(int i = 0; i < can.size(); i++) {
        if(can[i]) {
            next[i+p.first]++;
            next[i+p.second+1]--;
        }
    }

    int total = 0;
    for(int i = 0; i < can.size(); i++) {
        total += next[i];
        if(total > 0) {
            can[i] = true;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> d(n, -1);
    vector<vector<int>> adj(n);

    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        t--;
        join(d, i, t);
        adj[i].push_back(t);
    }

    vector<pair<int,int>> values;

    // For each representative, find cycle size
    for(int i = 0; i < n; i++) {
        if(d[i] < 0) {
            int cycle = findcycle(adj, i);
            values.push_back({cycle, size(d,i)});
        }
    }

    vector<bool> can(n+1,false);
    can[0] = true;
    for(auto i : values) {
        add(can, i);
    }

    for(int i = m; i >= 0; i--) {
        if(can[i]) {
            cout << i << endl;
            break;
        }
    }
}
