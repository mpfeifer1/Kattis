#include <bits/stdc++.h>

using namespace std;

// Returns {node, dist}
pair<int,int> getfurthest(vector<vector<int>>& adj, int start) {
    map<int,int> dist;

    queue<int> q;
    q.push(start);
    dist[start] = 0;

    int furthestdist = 0;
    int furthestidx = start;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(auto next : adj[curr]) {
            if(dist.count(next) == 0) {
                dist[next] = dist[curr] + 1;
                q.push(next);
                if(dist[next] > furthestdist) {
                    furthestdist = dist[next];
                    furthestidx = next;
                }
            }
        }
    }

    return {furthestidx, furthestdist};
}

int getdiam(vector<vector<int>>& adj, int start) {
    // Get furthest away, use that as start, get furthest away
    pair<int,int> s = getfurthest(adj, start);
    pair<int,int> t = getfurthest(adj, s.first);
    return t.second;
}

int find(vector<int>& d, int a) {
    if(d[a] == -1) {
        return a;
    }
    return d[a] = find(d, d[a]);
}

void join(vector<int>& d, int a, int b) {
    a = find(d, a);
    b = find(d, b);
    if(a == b) return;
    d[a] = b;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> d(n, -1);
    vector<vector<int>> adj(n);

    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        join(d, n1, n2);
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    vector<int> diameters;
    for(int i = 0; i < n; i++) {
        if(d[i] == -1) {
            diameters.push_back(getdiam(adj, i));
        }
    }

    sort(diameters.begin(), diameters.end());
    while(diameters.size() > 1) {
        // keep joining until done
        int wing1 = diameters.back() / 2;
        int wing2 = diameters.back() / 2;
        if(diameters.back() % 2 == 1) wing1++;
        diameters.pop_back();

        int wing3 = diameters.back() / 2;
        int wing4 = diameters.back() / 2;
        if(diameters.back() % 2 == 1) wing3++;
        diameters.pop_back();

        int op1 = wing1 + wing2;
        int op2 = wing3 + wing4;
        int op3 = wing1 + wing3 + 1;

        diameters.push_back(max({op1, op2, op3}));
    }

    cout << diameters[0] << endl;
}
