#include <bits/stdc++.h>

using namespace std;
typedef vector<vector<bool>> tetro;

vector<tetro> tetros;

void build() {
    tetros.push_back({{1,1,1,1},
                      {0,0,0,0},
                      {0,0,0,0},
                      {0,0,0,0}});
    tetros.push_back({{1,0,0,0},
                      {1,0,0,0},
                      {1,0,0,0},
                      {1,0,0,0}});

    tetros.push_back({{1,0,0,0},
                      {1,1,1,0},
                      {0,0,0,0},
                      {0,0,0,0}});
    tetros.push_back({{1,1,0,0},
                      {1,0,0,0},
                      {1,0,0,0},
                      {0,0,0,0}});
    tetros.push_back({{1,1,1,0},
                      {0,0,1,0},
                      {0,0,0,0},
                      {0,0,0,0}});
    tetros.push_back({{0,1,0,0},
                      {0,1,0,0},
                      {1,1,0,0},
                      {0,0,0,0}});

    tetros.push_back({{0,0,1,0},
                      {1,1,1,0},
                      {0,0,0,0},
                      {0,0,0,0}});
    tetros.push_back({{1,0,0,0},
                      {1,0,0,0},
                      {1,1,0,0},
                      {0,0,0,0}});
    tetros.push_back({{1,1,1,0},
                      {1,0,0,0},
                      {0,0,0,0},
                      {0,0,0,0}});
    tetros.push_back({{1,1,0,0},
                      {0,1,0,0},
                      {0,1,0,0},
                      {0,0,0,0}});

    tetros.push_back({{1,1,0,0},
                      {1,1,0,0},
                      {0,0,0,0},
                      {0,0,0,0}});

    tetros.push_back({{0,1,1,0},
                      {1,1,0,0},
                      {0,0,0,0},
                      {0,0,0,0}});
    tetros.push_back({{1,0,0,0},
                      {1,1,0,0},
                      {0,1,0,0},
                      {0,0,0,0}});

    tetros.push_back({{0,1,0,0},
                      {1,1,1,0},
                      {0,0,0,0},
                      {0,0,0,0}});
    tetros.push_back({{1,0,0,0},
                      {1,1,0,0},
                      {1,0,0,0},
                      {0,0,0,0}});
    tetros.push_back({{1,1,1,0},
                      {0,1,0,0},
                      {0,0,0,0},
                      {0,0,0,0}});
    tetros.push_back({{0,1,0,0},
                      {1,1,0,0},
                      {0,1,0,0},
                      {0,0,0,0}});

    tetros.push_back({{1,1,0,0},
                      {0,1,1,0},
                      {0,0,0,0},
                      {0,0,0,0}});
    tetros.push_back({{0,1,0,0},
                      {1,1,0,0},
                      {1,0,0,0},
                      {0,0,0,0}});
}

int n, m;

void apply(vector<vector<bool>>& v, int si, int sj, tetro t) {
    // Check piece can be used
    bool works = true;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(!t[i][j]) continue;
            if(si + i >= n) works = false;
            if(sj + j >= m) works = false;
        }
    }
    if(!works) return;

    // Use piece
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(t[i][j]) {
                v[si+i][sj+j] = !v[si+i][sj+j];
            }
        }
    }
}

int toint(vector<vector<bool>>& grid) {
    int ct = 1;
    int res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j]) res |= ct;
            ct <<= 1;
        }
    }
    return res;
}

vector<vector<bool>> extract(int t) {
    vector<vector<bool>> grid;
    grid.resize(n,vector<bool>(m,false));
    int ct = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(t & ct) {
                grid[i][j] = true;
            }
            ct <<= 1;
        }
    }
    return grid;
}

bool solve(vector<vector<bool>>& grid) {
    set<int> seen;
    queue<int> q;
    q.push(toint(grid));
    while(!q.empty()) {
        vector<vector<bool>> curr = extract(q.front());
        q.pop();

        int val = toint(curr);
        if(val == 0) return true;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(auto k : tetros) {
                    apply(curr,i,j,k);
                    int val = toint(curr);
                    if(!seen.count(val)) {
                        seen.insert(val);
                        q.push(val);
                    }
                    apply(curr,i,j,k);
                }
            }
        }
    }

    return false;
}

void compress(vector<vector<bool>>& v) {
    vector<vector<bool>> res;

    // Compress height
    for(int i = n-3; i < n; i++) {
        if(i < 0) continue;
        res.push_back({});
        for(int j = m - 4; j < m; j++) {
            if(j < 0) continue;
            res.back().push_back(v[i][j]);
        }
    }
    n = min(n,3);
    m = min(m,4);

    v = res;
    return;
}

int main() {
    build();

    cin >> n >> m;
    vector<vector<bool>> v;
    v.resize(n,vector<bool>(m));

    // Read the grid in
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c;
            cin >> c;
            v[i][j] = (c == 'X');
        }
    }

    // Solve the grid until it's 4x4 by using the 1x4 block
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m-4; j++) {
            if(v[i][j]) {
                apply(v,i,j,tetros[0]);
            }
        }
    }
    for(int j = 0; j < m; j++) {
        for(int i = 0; i < n-3; i++) {
            if(v[i][j]) {
                apply(v,i,j,tetros[1]);
            }
        }
    }

    // Compress the grid to a 4x4 or smaller
    compress(v);

    /*
    // Print the resulting grid
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << v[i][j];
        }
        cout << endl;
    }
    */

    // See if we can brute force the grid
    if(solve(v)) {
        cout << "possible" << endl;
    }
    else {
        cout << "impossible" << endl;
    }
}
