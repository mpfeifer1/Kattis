#include <bits/stdc++.h>

using namespace std;
int inf = 1 << 25;

vector<int> dx = {1,-1,0,0};
vector<int> dy = {0,0,1,-1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, x, y;
    cin >> n >> x >> y;

    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;

    vector<vector<int>> dist;
    dist.resize(x,vector<int>(y,inf));

    queue<pair<int,int>> q;
    for(int i = 0; i < n; i++) {
        int cx, cy;
        cin >> cx >> cy;
        dist[cx][cy] = 0;
        q.push({cx,cy});
    }

    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx < 0 || ny < 0 || nx >= x || ny >= y) {
                continue;
            }

            if(dist[nx][ny] > dist[cx][cy] + 1) {
                dist[nx][ny] = dist[cx][cy] + 1;
                q.push({nx,ny});
            }
        }
    }

    int lo = -1;
    int hi = min(dist[sx][sy],dist[ex][ey]);

    int ans;
    int path;
    while(hi >= lo) {
        int mi = (hi + lo) / 2;

        queue<pair<int,int>> q;
        vector<vector<int>> vis;
        vis.resize(x,vector<int>(y,inf));

        vis[sx][sy] = 0;
        q.push({sx,sy});

        while(!q.empty()) {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if(nx < 0 || ny < 0 || nx >= x || ny >= y) {
                    continue;
                }

                if(dist[nx][ny] < mi) {
                    continue;
                }

                if(vis[nx][ny] > vis[cx][cy] + 1) {
                    vis[nx][ny] = vis[cx][cy] + 1;
                    q.push({nx,ny});
                }
            }
        }

        if(vis[ex][ey] == inf) {
            hi = mi - 1;
        }
        else {
            lo = mi + 1;
            ans = mi;
            path = vis[ex][ey];
        }
    }

    cout << ans << " " << path << endl;
}
