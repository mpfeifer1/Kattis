#include <bits/stdc++.h>

using namespace std;

int x, y, z;

struct loc {
    int x, y, z;
};

bool inrange(int a, int b, int c) {
    return (a >= 0 && b >= 0 && b >= 0 && a < x && b < y && c < z);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> x >> y >> z) {
        loc s, e;

        if(x == 0 || y == 0 || z == 0) {
            break;
        }

        vector<vector<vector<int>>> v(x);
        for(auto& i : v) {
            i.resize(y, vector<int>(z, -2));
        }

        for(int i = 0; i < x; i++) {
            for(int j = 0; j < y; j++) {
                for(int k = 0; k < z; k++) {
                    char c;
                    cin >> c;
                    if(c == '#') {
                        v[i][j][k] = -1;
                    }
                    if(c == 'S') {
                        s.x = i;
                        s.y = j;
                        s.z = k;
                    }
                    if(c == 'E') {
                        e.x = i;
                        e.y = j;
                        e.z = k;
                    }
                }
            }
        }

        // BFS
        queue<loc> q;
        q.push(s);
        v[s.x][s.y][s.z] = 0;

        while(!q.empty()) {
            loc c = q.front();
            q.pop();

            // Try 6 positions
            if(inrange(c.x-1,c.y,c.z) && v[c.x-1][c.y][c.z] == -2) {
                v[c.x-1][c.y][c.z] = v[c.x][c.y][c.z] + 1;
                q.push({c.x-1,c.y,c.z});
            }
            if(inrange(c.x+1,c.y,c.z) && v[c.x+1][c.y][c.z] == -2) {
                v[c.x+1][c.y][c.z] = v[c.x][c.y][c.z] + 1;
                q.push({c.x+1,c.y,c.z});
            }
            if(inrange(c.x,c.y-1,c.z) && v[c.x][c.y-1][c.z] == -2) {
                v[c.x][c.y-1][c.z] = v[c.x][c.y][c.z] + 1;
                q.push({c.x,c.y-1,c.z});
            }
            if(inrange(c.x,c.y+1,c.z) && v[c.x][c.y+1][c.z] == -2) {
                v[c.x][c.y+1][c.z] = v[c.x][c.y][c.z] + 1;
                q.push({c.x,c.y+1,c.z});
            }
            if(inrange(c.x,c.y,c.z-1) && v[c.x][c.y][c.z-1] == -2) {
                v[c.x][c.y][c.z-1] = v[c.x][c.y][c.z] + 1;
                q.push({c.x,c.y,c.z-1});
            }
            if(inrange(c.x,c.y,c.z+1) && v[c.x][c.y][c.z+1] == -2) {
                v[c.x][c.y][c.z+1] = v[c.x][c.y][c.z] + 1;
                q.push({c.x,c.y,c.z+1});
            }
        }

        if(v[e.x][e.y][e.z] < 0) {
            cout << "Trapped!" << endl;
        }
        else {
            cout << "Escaped in " << v[e.x][e.y][e.z] << " minute(s)." << endl;
        }
    }
}
