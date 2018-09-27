#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;

bool inrange(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m;
}

struct state {
    int i, j, w;
};

bool operator<(const state& s1, const state& s2) {
    if(s1.w == s2.w) {
        if(s1.j == s2.j) {
            return s1.i < s2.i;
        }
        return s1.j < s2.j;
    }
    return s1.w > s2.w;
}

ll bfs(vector<vector<int>>& in, int startx, int starty) {
    vector<vector<int>> best(n, vector<int>(m,0));

    priority_queue<state> q;
    best[startx][starty] = in[startx][starty];
    q.push({startx,starty,0});

    vector<int> dx = {-1,-1,-1,0,0,1,1,1};
    vector<int> dy = {-1,0,1,-1,1,-1,0,1};

    set<pair<int,int>> vis;

    while(!q.empty()) {
        int currx = q.top().i;
        int curry = q.top().j;
        q.pop();

        if(vis.count({currx,curry}) > 0) continue;
        vis.insert({currx,curry});

        for(int k = 0; k < 8; k++) {
            int nextx = currx + dx[k];
            int nexty = curry + dy[k];

            if(!inrange(nextx,nexty)) continue;

            if(best[nextx][nexty] > max(best[currx][curry], in[nextx][nexty])) {
                best[nextx][nexty] = max(best[currx][curry], in[nextx][nexty]);
                q.push({nextx,nexty,best[nextx][nexty]});
            }
        }
    }

    ll total = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            total -= best[i][j];
        }
    }

    return total;
}

int main() {
    cin >> n >> m;
    vector<vector<int>> in(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> in[i][j];
        }
    }
    int startx, starty;
    cin >> startx >> starty;
    startx--; starty--;

    cout << bfs(in, startx, starty) << endl;
}
