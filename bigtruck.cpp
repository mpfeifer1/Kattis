#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int inf = 2 << 28;

int main() {
    int n;
    cin >> n;

    vector<int> items(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> items[i];
    }

    vector<vector<int>> dist;
    dist.resize(n+1, vector<int>(n+1, inf));

    int c;
    cin >> c;
    for(int i = 0; i < c; i++) {
        int l1, l2, d;
        cin >> l1 >> l2 >> d;
        dist[l1][l2] = d;
        dist[l2][l1] = d;
    }

    // Pairs are distance, items
    vector<pair<int, int>> visited;
    visited.resize(n+1, {inf, inf});

    queue<int> q;
    visited[1] = {0, items[1]};
    q.push(1);

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(int i = 1; i <= n; i++) {
            // If we can get there faster
            if(visited[curr].first + dist[curr][i] < visited[i].first) {
                visited[i].first = visited[curr].first + dist[curr][i];
                visited[i].second = visited[curr].second + items[i];
                q.push(i);
            }
            // If we can get there same time, less items
            else if(visited[curr].first + dist[curr][i] == visited[i].first && visited[curr].second + items[i] > visited[i].second) {
                visited[i].first = visited[curr].first + dist[curr][i];
                visited[i].second = visited[curr].second + items[i];
                q.push(i);
            }
        }
    }

    if(visited[n].first < inf) {
        cout << visited[n].first << " " << visited[n].second << endl;
    }
    else {
        cout << "impossible" << endl;
    }
}
