#include <bits/stdc++.h>

using namespace std;
int inf = 1 << 30;

int n, m;

bool inrange(int x, int y) {
    return x >= 0 && y >= 0 && x < n+2 && y < m;
}

void solve() {
    vector<vector<int>> board(n+2, vector<int>(m,0));
    vector<vector<int>> dist(n+2, vector<int>(m,inf));
    vector<vector<pair<int,int>>> par(n+2, vector<pair<int,int>>(m, {inf,inf}));

    // Read in, and subtract to actual vals
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            char t;
            cin >> t;
            board[i][j] = t - '0';
        }
    }

    dist[0][0] = 0;
    priority_queue<pair<int, pair<int,int>>> q;
    q.push({0,{0,0}});

    while(!q.empty()) {
        int currx = q.top().second.first;
        int curry = q.top().second.second;
        q.pop();

        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                int nextx = currx + i;
                int nexty = curry + j;
                if(!inrange(nextx,nexty)) {
                    continue;
                }
                if(dist[currx][curry] + board[nextx][nexty] < dist[nextx][nexty]) {
                    q.push({-dist[nextx][nexty], {nextx,nexty}});
                    dist[nextx][nexty] = dist[currx][curry] + board[nextx][nexty];
                    par[nextx][nexty] = {currx,curry};
                }
            }
        }
    }

    int currx = n+1;
    int curry = m-1;
    while(currx != inf && curry != inf) {
        board[currx][curry] = ' ' - '0';
        pair<int,int> prev = par[currx][curry];
        currx = prev.first;
        curry = prev.second;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            cout << char(board[i][j]+'0');
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    while(cin >> n && cin >> m) {
        if(n == 0 && m == 0) {
            break;
        }
        solve();
    }
}
