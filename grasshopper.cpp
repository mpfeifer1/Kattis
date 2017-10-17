#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int INF = (1 << 31);

bool inrange(int w, int h, int x, int y) {
    return (x >= 0 && y >= 0 && x < w && y < h);
}

int main() {
    int x, y, startx, starty, endx, endy;
    while(cin >> x && cin >> y && cin >> startx && cin >> starty && cin >> endx && cin >> endy) {
        vector<vector<int>> v;
        v.resize(x, vector<int>(y, INF));

        v[startx-1][starty-1] = 0;

        queue<pair<int, int>> q;
        q.push({startx-1, starty-1});

        while(!q.empty()) {
            int currx = q.front().first;
            int curry = q.front().second;
            int currval = v[currx][curry];
            q.pop();

            vector<pair<int, int>> modifiers;
            modifiers.push_back({-2, -1});
            modifiers.push_back({-1, -2});
            modifiers.push_back({+2, -1});
            modifiers.push_back({+1, -2});
            modifiers.push_back({-2, +1});
            modifiers.push_back({-1, +2});
            modifiers.push_back({+2, +1});
            modifiers.push_back({+1, +2});

            for(auto m : modifiers) {
                if(inrange(x, y, currx+m.first, curry+m.second) && v[currx+m.first][curry+m.second] == INF) {
                    v[currx+m.first][curry+m.second] = currval+1;
                    q.push({currx+m.first, curry+m.second});
                }
            }
        }

        if(v[endx-1][endy-1] == INF) {
            cout << "impossible" << endl;
        }
        else {
            cout << v[endx-1][endy-1] << endl;
        }
    }
}
