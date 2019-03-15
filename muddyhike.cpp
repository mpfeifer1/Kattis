#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = 1000001;

vector<int> dx = {1,-1,0,0};
vector<int> dy = {0,0,1,-1};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v;
    v.resize(n,vector<int>(m+2,-1));

    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }

    vector<vector<int>> best;
    best.resize(n,vector<int>(m+2,inf));

    vector<vector<bool>> vis;
    vis.resize(n,vector<bool>(m+2,false));

    best[0][0] = 0;
    set<tuple<int,int,int>> q;
    q.insert({0,0,0});

    while(!q.empty()) {
        int currx = get<1>(*q.begin());
        int curry = get<2>(*q.begin());
        q.erase(q.begin());

        for(int i = 0; i < 4; i++) {
            int nextx = currx + dx[i];
            int nexty = curry + dy[i];

            if(nextx >= 0 && nexty >= 0 && nextx < n && nexty < m+2) {
                int nextval = max(best[currx][curry],v[nextx][nexty]);
                if(nextval < best[nextx][nexty]) {
                    best[nextx][nexty] = nextval;
                    q.insert({nextval,nextx,nexty});
                }
            }
        }
    }

    cout << best[0][m+1] << endl;
}
