#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

typedef long long ll;

struct check {
    int i;
    int j;
    int pi;
    int pj;
};

bool inrange(int i, int j, int r, int c) {
    if(i < 0) {
        return false;
    }
    if(j < 0) {
        return false;
    }
    if(i >= r) {
        return false;
    }
    if(j >= c) {
        return false;
    }
    return true;
}

bool dfs(vector<vector<bool>>& v, vector<vector<char>>& graph, int i, int j, int row, int col) {
    int starti, startj;
    starti = i;
    startj = j;

    stack<check> todo;
    todo.push({i,j,-5,-5});

    check c = todo.top();

    bool connected = false;

    while(!todo.empty()) {
        c = todo.top();
        todo.pop();
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                int thisi = c.i + i;
                int thisj = c.j + j;

                if(thisi == starti && thisj == startj) {
                    connected = true;
                }

                if(!inrange(thisi, thisj, row, col)) {
                    continue;
                }

                if(i == 0 && j == 0) {
                    continue;
                }

                if(thisi == c.pi && thisj == c.pj) {
                    continue;
                }

                if(!v[thisi][thisj] && graph[thisi][thisj] == '#') {
                    todo.push({thisi, thisj, c.i, c.j});
                    v[thisi][thisj] = true;
                }

            }
        }
    }

    return connected;
}

int main() {
    int r, c;
    cin >> r >> c;

    vector<vector<char>> graph;
    graph.resize(r);
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            char ch;
            cin >> ch;
            graph[i].push_back(ch);
        }
    }

    vector<vector<bool>> visited;
    visited.resize(r, vector<bool>(c, false));

    int total = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(!visited[i][j]) {
                if(graph[i][j] == '#' && dfs(visited, graph, i, j, r, c)) {
                    total++;
                }
            }
        }
    }

    cout << total << endl;
}

