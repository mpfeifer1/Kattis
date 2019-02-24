#include <bits/stdc++.h>

using namespace std;

struct state {
    int x, y;
    int r, l, u, d, b, f;
};

bool operator<(const state& s1, const state& s2) {
    return tie(s1.x,s1.y,s1.r,s1.l,s1.u,s1.d,s1.b,s1.f) <
           tie(s2.x,s2.y,s2.r,s2.l,s2.u,s2.d,s2.b,s2.f);
}

struct dir {
    int dx;
    int dy;
    int rot;
};

int n, m;

bool inrange(state s) {
    return s.x >= 0 && s.y >= 0 && s.x < n && s.y < m;
}

int main() {
    cin >> n >> m;

    vector<vector<int>> v;
    v.resize(n,vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    vector<dir> dirs = {{-1,0,'N'},{1,0,'S'},{0,-1,'W'},{0,1,'E'}};

    set<state> vis;
    state initial = {0,0, -1,-1,-1,v[0][0],-1,-1};
    stack<state> q;
    q.push(initial);

    while(!q.empty()) {
        state curr = q.top();
        q.pop();

        if(curr.x == n-1 && curr.y == m-1) {
            cout << "YES" << endl;
            return 0;
        }

        for(auto i : dirs) {
            state next = curr;
            next.x += i.dx;
            next.y += i.dy;
            if(!inrange(next)) continue;

            // roll the cube

            if(i.rot == 'N') {
                int temp = next.d;
                next.d = next.b;
                next.b = next.u;
                next.u = next.f;
                next.f = temp;
            }

            if(i.rot == 'S') {
                int temp = next.f;
                next.f = next.u;
                next.u = next.b;
                next.b = next.d;
                next.d = temp;
            }

            if(i.rot == 'E') {
                int temp = next.d;
                next.d = next.r;
                next.r = next.u;
                next.u = next.l;
                next.l = temp;
            }
            if(i.rot == 'W') {
                int temp = next.l;
                next.l = next.u;
                next.u = next.r;
                next.r = next.d;
                next.d = temp;
            }

            // check if we're negative 1 or the spot matches
            if(next.d == -1) {
                next.d = v[next.x][next.y];
            }
            if(next.d != v[next.x][next.y]) {
                continue;
            }

            if(!vis.count(next)) {
                vis.insert(next);
                q.push(next);
            }
        }
    }

    cout << "NO" << endl;
}
