#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int turn(char move, int initial) {
    int newmove = initial;
    if(move == 'R') {
         newmove += 1;
    }
    if(move == 'B') {
         newmove += 2;
    }
    if(move == 'L') {
         newmove += 3;
    }

    newmove %= 4;
    return newmove;
}

void walk(vector<string>& maze, int& x, int& y, int dir) {
    if(dir == 0) {
        x++;
    }
    if(dir == 1) {
        y--;
    }
    if(dir == 2) {
        x--;
    }
    if(dir == 3) {
        y++;
    }

    if(x == maze[0].size()-1) {
        for(auto& x : maze) {
            x.push_back('#');
        }
    }

    string temp;
    temp.resize(maze[0].size(), '#');
    if(y == maze.size()-1) {
        maze.push_back(temp);
    }
    if(y == 0) {
        maze.insert(maze.begin(), temp);
        y++;
    }

    maze[y][x] = '.';
}

int main() {
    int cases;
    cin >> cases;
    cout << cases << endl;

    for(int i = 0; i < cases; i++) {
        string path;
        cin >> path;

        vector<string> maze = {"##", ".#", "##"};
        int x = 0;
        int y = 1;

        // 0 - Right
        // 1 - Down
        // 2 - Left
        // 3 - Up
        int dir = 0;

        // Simulate the maze
        for(auto move : path) {
            dir = turn(move, dir);
            walk(maze, x, y, dir);
        }

        // Reverse the output
        reverse(maze.begin(), maze.end());

        // Print the output
        cout << maze.size() << " " << maze[0].size() << endl;
        for(auto line : maze) {
            cout << line << endl;
        }
    }
}
