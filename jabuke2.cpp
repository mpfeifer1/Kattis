#include <bits/stdc++.h>

using namespace std;
int inf = 1 << 29;

int n, m;
vector<vector<char>> v;

vector<int> dx = {-1,1,0,0};
vector<int> dy = {0,0,1,-1};

bool inrange(int x, int y) {
    return x < n && y < m && x >= 0 && y >= 0;
}

int sq(int i) {
    return i*i;
}

int getcost(pair<int,int>& p1, pair<int,int>& p2) {
    return sq(p1.first-p2.first) + sq(p1.second - p2.second);
}

vector<vector<int>> vis;

int t = 0;
int bfs(pair<int,int>& start) {
    queue<pair<int,int>> q; 
    q.push(start);

    int ans = inf;

    while(!q.empty()) {
        int currx = q.front().first;
        int curry = q.front().second;
        q.pop();

        if(vis[currx][curry] == t) continue;
        vis[currx][curry] = t;

        pair<int,int> p = {currx,curry};

        if(getcost(start,p) > ans) continue;

        if(v[currx][curry] == 'x') {
            ans = min(ans, getcost(start,p));
        }

        for(int i = 0; i < 4; i++) {
            int nextx = currx + dx[i];
            int nexty = curry + dy[i];
            if(inrange(nextx,nexty)) {
                q.push({nextx,nexty});
            }
        }
    }

    t++;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    v.resize(n,vector<char>(m));

    vector<pair<int,int>> s;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    vis.resize(n,vector<int>(m,-1));

    int q;
    cin >> q;
    while(q--) {
        int x, y;
        cin >> x >> y;
        x--; y--;

        pair<int,int> p = {x,y};
        cout << bfs(p) << endl;
        v[x][y] = 'x';
    }
}
