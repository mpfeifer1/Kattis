#include <bits/stdc++.h>

using namespace std;
int inf = 1 << 29;

vector<int> dx = {-1,1,0,0};
vector<int> dy = {0,0,1,-1};

bool inrange(int x, int y, int mx, int my) {
    return x >= 0 && y >= 0 && x < mx && y < my;
}

int main() {
    int r, c, n;
    cin >> r >> c >> n;

    vector<vector<int>> v(r,vector<int>(c,inf));

    queue<pair<int,int>> q;
    for(int i = 0 ; i < n; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        n1--;
        n2--;
        q.push({n1,n2});
        v[n1][n2] = 1;
    }

    int hi = 1;

    while(!q.empty()) {
        int currx = q.front().first;
        int curry = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nextx = currx + dx[i];
            int nexty = curry + dy[i];
            if(!inrange(nextx,nexty,r,c)) continue;
            if(v[nextx][nexty] == inf) {
                v[nextx][nexty] = v[currx][curry] + 1;
                hi = v[nextx][nexty];
                q.push({nextx,nexty});
            }
        }
    }

    cout << hi << endl;
}
