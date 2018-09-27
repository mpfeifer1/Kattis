#include <bits/stdc++.h>

using namespace std;
int inf = 1 << 15;

bool inrange(int i, int j) {
    return i >= 0 && j >= 0 && i < 8 && j < 8;
}

void bfs(vector<vector<int>>& dist, int starti, int startj) {
    queue<pair<int,int>> q;
    q.push({starti,startj});
    dist[starti][startj] = 0;

    vector<int> dx = {1,2,2,1,-1,-2,-2,-1};
    vector<int> dy = {-2,-1,1,2,2,1,-1,-2};

    while(!q.empty()) {
        int curri = q.front().first;
        int currj = q.front().second;
        q.pop();

        for(int k = 0; k < 8; k++) {
            int nexti = curri + dx[k];
            int nextj = currj + dy[k];

            if(!inrange(nexti,nextj)) continue;
            if(dist[nexti][nextj] > dist[curri][currj] + 1) {
                dist[nexti][nextj] = dist[curri][currj] + 1;
                q.push({nexti,nextj});
            }
        }
    }
}

void solve() {
    string s;
    cin >> s;

    // Run BFS
    vector<vector<int>> dist(8, vector<int>(8,inf));
    bfs(dist, s[0]-'a', s[1]-'1');

    // Find farthest dist, print it
    int far = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            far = max(far, dist[i][j]);
        }
    }
    cout << far << " ";

    // Find all at that dist
    vector<string> ans;
    for(int j = 7; j >= 0; j--) {
        for(int i = 0; i < 8; i++) {
            if(dist[i][j] == far) {
                string here;
                here += i+'a';
                here += j+'1';
                cout << here << " ";
            }
        }
    }
    cout << endl;
}

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        solve();
    }
}
