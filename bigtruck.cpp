#include <bits/stdc++.h>

using namespace std;
int inf = 1 << 30;

struct node {
    int dest;

    int dist;
    int items;
};

bool operator<(const node& n1, const node& n2) {
    if(n1.dist == n2.dist) {
        return n1.items < n2.items;
    }
    return n1.dist > n2.dist;
}

int main() {
    int n;
    cin >> n;

    vector<int> items(n);
    for(auto& i : items) {
        cin >> i;
    }

    int m;
    cin >> m;

    // {dest,weight}
    vector<vector<pair<int,int>>> adj(n);

    for(int i = 0; i < m; i++) {
        int n1, n2, w;
        cin >> n1 >> n2 >> w;
        n1--; n2--;

        adj[n1].push_back({n2,w});
        adj[n2].push_back({n1,w});
    }

    vector<int> bestDist(n,inf);
    vector<int> bestItem(n,0);
    vector<bool> vis(n,false);

    priority_queue<node> q;

    q.push({0,0,items[0]});
    bestDist[0] = 0;
    bestItem[0] = items[0];

    while(!q.empty()) {
        int curr = q.top().dest;
        q.pop();

        if(vis[curr]) {
            continue;
        }
        vis[curr] = true;

        for(auto i : adj[curr]) {
            int next = i.first;

            if(bestDist[next] > bestDist[curr] + i.second) {
                bestDist[next] = bestDist[curr] + i.second;
                bestItem[next] = bestItem[curr] + items[next];
                q.push({next,bestDist[next],bestItem[next]});
            }

            else if(bestDist[next] == bestDist[curr] + i.second) {
                bestItem[next] = max(bestItem[next], bestItem[curr] + items[next]);
                q.push({next,bestDist[next],bestItem[next]});
            }
        }
    }

    if(bestDist[n-1] >= inf) {
        cout << "impossible" << endl;
    }
    else {
        cout << bestDist[n-1] << " " << bestItem[n-1] << endl;
    }
}
