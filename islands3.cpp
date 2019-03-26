#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n,m;
vector<vector<char>> v;
vector<vector<bool>> vis;

vector<int> dx = {1,-1,0,0};
vector<int> dy = {0,0,1,-1};

void dfs(int i, int j) {
    if(vis[i][j]) return;
    vis[i][j] = true;
    for(int k = 0; k < 4; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if(ni < 0) continue;
        if(nj < 0) continue;
        if(ni >= n) continue;
        if(nj >= m) continue;

        if(v[ni][nj] == 'C' || v[ni][nj] == 'L') {
            dfs(ni,nj);
        }
    } 
}

int main() {
    cin >> n >> m;

    v.resize(n,vector<char>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    vis.resize(n,vector<bool>(m,false));

    int ct = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j] && v[i][j] == 'L') {
                dfs(i,j);
                ct++;
            }
        }
    }

    cout << ct << endl;
}
