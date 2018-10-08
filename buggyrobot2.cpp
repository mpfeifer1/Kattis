#include <bits/stdc++.h>

using namespace std;
const int inf = 1 << 30;

struct state {
    int x, y, pos;
};

bool operator<(const state& s1, const state& s2) {
    if(s1.x == s2.x) {
        if(s1.y == s2.y) {
            return s1.pos < s2.pos;
        }
        return s1.y < s2.y;
    }
    return s1.x < s2.x;
}

int n, m;
string command;
vector<vector<char>> board;
map<state, int> dist;

pair<int,int> getmove(char move, int x, int y) {
    if(move == 'L') {
        if(board[x][y-1] != '#') {
            return {x,y-1};
        }
    }
    if(move == 'R') {
        if(board[x][y+1] != '#') {
            return {x,y+1};
        }
    }
    if(move == 'U') {
        if(board[x-1][y] != '#') {
            return {x-1,y};
        }
    }
    if(move == 'D') {
        if(board[x+1][y] != '#') {
            return {x+1,y};
        }
    }

    return {x,y};
}

void addmove(priority_queue<pair<int,state>>& q, state curr, state next, int add) {
    if(dist.count(next) == 0) {
        dist[next] = inf;
    }
    if(dist[next] > dist[curr] + add) {
        dist[next] = dist[curr] + add;
        q.push({-dist[next], next});
    }
}

void solve(int startx, int starty) {
    // Initialize priority queue
    priority_queue<pair<int,state>> q;
    dist[{startx,starty,0}] = 0;
    q.push({0,{startx,starty,0}});

    while(!q.empty()) {
        state curr = q.top().second;
        q.pop();

        int x = curr.x;
        int y = curr.y;
        int pos = curr.pos;

        if(board[x][y] == 'E') {
            cout << dist[curr] << endl;
            break;
        }

        // If we have moves left, we can use these cases
        if(pos < command.size()) {
            // Use this move
            pair<int,int> h = getmove(command[pos], x, y);
            state next = {h.first, h.second, pos+1};
            addmove(q, curr, next, 0);

            // Delete this move
            state skip = {x, y, pos+1};
            addmove(q, curr, skip, 1);
        }

        // Whether or not we have moves left, try adding a move in every direction
        for(auto i : {'R', 'L', 'U', 'D'}) {
            pair<int,int> p = getmove(i, x, y);
            state nexthere = {p.first, p.second, pos};
            addmove(q, curr, nexthere, 1);
        }
    }
}

int main() {
    cin >> n >> m;

    int startx, starty;

    board.resize(n+2, vector<char>(m+2,'#'));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'R') {
                board[i][j] = '.';
                startx = i;
                starty = j;
            }
        }
    }

    cin >> command;

    for(int i = 0; i < n+2; i++) {
        for(int j = 0; j < m+2; j++) {
            for(int k = 0; k <= command.size(); k++) {
                dist[{i,j,k}] = inf;
            }
        }
    }

    solve(startx, starty);
}
