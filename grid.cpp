#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int inf = 2 << 28;

bool inrange(int n, int m, int x, int y) {
    if(x < 0) {
        return false;
    }
    if(y < 0) {
        return false;
    }
    if(x >= n) {
        return false;
    }
    if(y >= m) {
        return false;
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v;
    v.resize(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c;
            cin >> c;
            v[i][j] = c - '0';
        }
    }

    vector<vector<int>> dist;
    dist.resize(n, vector<int>(m, inf));

    queue<pair<int, int>> q;
    dist[0][0] = 0;
    q.push({0,0});

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        int range = v[x][y];
        if(inrange(n, m, x-range, y)) {
            if(dist[x][y] + 1 < dist[x-range][y]) {
                dist[x-range][y] = dist[x][y] + 1;
                q.push({x-range,y});
            }
        }
        if(inrange(n, m, x+range, y)) {
            if(dist[x][y] + 1 < dist[x+range][y]) {
                dist[x+range][y] = dist[x][y] + 1;
                q.push({x+range,y});
            }
        }
        if(inrange(n, m, x, y-range)) {
            if(dist[x][y] + 1 < dist[x][y-range]) {
                dist[x][y-range] = dist[x][y] + 1;
                q.push({x,y-range});
            }
        }
        if(inrange(n, m, x, y+range)) {
            if(dist[x][y] + 1 < dist[x][y+range]) {
                dist[x][y+range] = dist[x][y] + 1;
                q.push({x,y+range});
            }
        }
    }

    int d = dist[n-1][m-1];
    if(d == inf) {
        cout << "-1" << endl;
    }
    else {
        cout << d << endl;
    }
}
