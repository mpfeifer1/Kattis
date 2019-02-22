#include <bits/stdc++.h>

using namespace std;
const int inf = 1 << 29;
const int MAXSAVE = 200;

struct state {
    int i, j, rot, saved;
};

struct block {
    vector<bool> dirs;
};

bool operator<(const state& s1, const state& s2) {
    if(s1.i == s2.i) {
        if(s1.j == s2.j) {
            if(s1.rot == s2.rot) {
                return s1.saved < s2.saved;
            }
            return s1.rot < s2.rot;
        }
        return s1.j < s2.j;
    }
    return s1.i < s2.i;
}

inline block toblock(string s) {
    block b;
    b.dirs.resize(4,false);
    for(auto i : s) {
        if(i == 'N') b.dirs[0] = true;
        if(i == 'E') b.dirs[1] = true;
        if(i == 'S') b.dirs[2] = true;
        if(i == 'W') b.dirs[3] = true;
    }
    return b;
}

int n, m;
int sx, sy, ex, ey;
int vis[20][20][4][MAXSAVE+1];
int maxe[20][20][4];
vector<vector<block>> v;

inline bool inrange(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m;
}

inline bool conn(state& next, state& curr) {
    int i1 = curr.i;
    int j1 = curr.j;
    int rot1 = curr.rot;
    int i2 = next.i;
    int j2 = next.j;
    int rot2 = next.rot;

    block n1 = v[i1][j1];
    block n2 = v[i2][j2];

    bool u1 = n1.dirs[(0-rot1+4)%4];
    bool r1 = n1.dirs[(1-rot1+4)%4];
    bool d1 = n1.dirs[(2-rot1+4)%4];
    bool l1 = n1.dirs[(3-rot1+4)%4];

    bool u2 = n2.dirs[(0-rot2+4)%4];
    bool r2 = n2.dirs[(1-rot2+4)%4];
    bool d2 = n2.dirs[(2-rot2+4)%4];
    bool l2 = n2.dirs[(3-rot2+4)%4];

    // 1 below 2
    if(i1 > i2) {
        return u1 && d2;
    }

    // 1 above 2
    if(i1 < i2) {
        return d1 && u2;
    }

    // 1 to right of 2
    if(j1 > j2) {
        return r2 && l1;
    }

    // 1 to left of 2
    if(j1 < j2) {
        return l2 && r1;
    }

    return false;
}

inline int get(state s) {
    return vis[s.i][s.j][s.rot][s.saved];
}

inline void put(state s, int n) {
    vis[s.i][s.j][s.rot][s.saved] = n;
}

int dijk() {
    put({sx,sy,0,0},0);
    set<pair<int,state>> q;
    q.insert({0,{sx,sy,0,0}});

    while(!q.empty()) {
        state curr = (*q.begin()).second;
        q.erase(q.begin());

        // For each surrounding block, we can (optionally) use
        // a rotation, then move there
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};

        for(int n = 0; n < 4; n++) { // Each of our rotations
            for(int d = 0; d < 4; d++) { // Each surrounding block
                for(int r = 0; r < 4; r++) { // Each of their rotations
                    //Get our coords, check it's valid
                    int nexti = curr.i+dx[d];
                    int nextj = curr.j+dy[d];
                    if(!inrange(nexti,nextj)) continue;

                    // Build new state
                    state next = {nexti, nextj, r, curr.saved+1};

                    // Find cost here
                    int cost = 1; // cost is 1 if we need 2 rotations, plus we always need 1 for the turn
                    if(n == 2) cost++;
                    int fixablecost = min(r,4-r);
                    if(n > 0) fixablecost++;

                    // Use saved rotations
                    while(next.saved > 0 && fixablecost > 0) {
                        next.saved--;
                        fixablecost--;
                    }

                    // Figure out distance for next state
                    int nextd = get(curr) + cost + fixablecost;

                    // Build state to compare against
                    state temp = curr;
                    temp.rot = (temp.rot + n) % 4;

                    // Make sure our blocks connect
                    if(!conn(temp,next)) continue;

                    // If we're using too much, don't go
                    if(maxe[next.i][next.j][next.rot] < nextd - next.saved) {
                        continue;
                    }
                    maxe[next.i][next.j][next.rot] = nextd - next.saved;

                    // If better, use
                    if(get(next) > nextd) {
                        put(next,nextd);
                        q.insert({nextd,next});
                    }
                }
            }
        }
    }

    int ans = inf;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j <= MAXSAVE; j++) {
            ans = min(ans,get({ex,ey,i,j}));
        }
    }
    return ans;
}

int main() {
    cin >> n >> m;

    cin >> sx >> sy >> ex >> ey;
    sx--; sy--; ex--; ey--;;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int r = 0; r < 4; r++) {
                for(int s = 0; s <= MAXSAVE; s++) {
                    vis[i][j][r][s] = inf;
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int r = 0; r < 4; r++) {
                maxe[i][j][r] = inf;
            }
        }
    }
    v.resize(n,vector<block>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            string s;
            cin >> s;
            v[i][j] = toblock(s);
        }
    }

    cout << dijk() << endl;
}
