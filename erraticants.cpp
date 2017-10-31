#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int START = 65;
int inf = 1 << 30;

struct spot {
    bool N;
    bool S;
    bool E;
    bool W;

    int dist = inf;
};

int main() {
    int cases;
    cin >> cases;

    while(cases--) {
        // Build grid
        vector<vector<spot>> v;
        spot s;
        s.N = false, s.S = false;
        s.E = false, s.W = false;
        s.dist = inf;
        v.resize(130, vector<spot>(130, s));

        // Read in path
        int n;
        cin >> n;
        vector<char> path(n);
        for(int i = 0; i < path.size(); i++) {
            cin >> path[i];
        }

        // Fill in grid
        int x = START;
        int y = START;
        for(auto c : path) {
            if(c == 'N') {
                v[x][y].N = true;
                y++;
                v[x][y].S = true;
            }
            if(c == 'S') {
                v[x][y].S = true;
                y--;
                v[x][y].N = true;
            }
            if(c == 'E') {
                v[x][y].E = true;
                x--;
                v[x][y].W = true;
            }
            if(c == 'W') {
                v[x][y].W = true;
                x++;
                v[x][y].E = true;
            }
        }

        queue<pair<int, int>> q;
        q.push({START, START});
        v[START][START].dist = 0;

        while(!q.empty()) {
            int currx = q.front().first;
            int curry = q.front().second;
            q.pop();

            spot curr = v[currx][curry];
            if(curr.N) {
                if(curr.dist + 1 < v[currx][curry+1].dist) {
                    v[currx][curry+1].dist = curr.dist + 1;
                    q.push({currx, curry+1});
                }
            }
            if(curr.S) {
                if(curr.dist + 1 < v[currx][curry-1].dist) {
                    v[currx][curry-1].dist = curr.dist + 1;
                    q.push({currx, curry-1});
                }
            }
            if(curr.E) {
                if(curr.dist + 1 < v[currx-1][curry].dist) {
                    v[currx-1][curry].dist = curr.dist + 1;
                    q.push({currx-1, curry});
                }
            }
            if(curr.W) {
                if(curr.dist + 1 < v[currx+1][curry].dist) {
                    v[currx+1][curry].dist = curr.dist + 1;
                    q.push({currx+1, curry});
                }
            }
        }

        cout << v[x][y].dist << endl;
    }
}
