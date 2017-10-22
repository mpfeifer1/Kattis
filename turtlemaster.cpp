#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<vector<char>> v;
    v.resize(10, vector<char>(10));

    for(int i = 1; i <= 8; i++) {
        for(int j = 1; j <= 8; j++) {
            cin >> v[i][j];
        }
    }

    string command;
    cin >> command;

    int dir = 0;
    // 0: Right
    // 1: Up
    // 2: Left
    // 3: Down

    int x = 1;
    int y = 8;

    for(auto c : command) {
        if(c == 'F') {
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

            if(x == 0 || x == 9 || y == 0 || y == 9) {
                cout << "Bug!" << endl;
                return 0;
            }

            if(v[y][x] == 'C' || v[y][x] == 'I') {
                cout << "Bug!" << endl;
                return 0;
            }
        }
        if(c == 'L') {
            dir++;
            dir %= 4;
        }
        if(c == 'R') {
            dir--;
            if(dir < 0) {
                dir = 3;
            }
        }
        if(c == 'X') {
            int tempx = x;
            int tempy = y;
            if(dir == 0) {
                tempx++;
            }
            if(dir == 1) {
                tempy--;
            }
            if(dir == 2) {
                tempx--;
            }
            if(dir == 3) {
                tempy++;
            }

            if(tempx == 0 || tempx == 9 || tempy == 0 || tempy == 9) {
                cout << "Bug!" << endl;
                return 0;
            }

            if(v[tempy][tempx] != 'I') {
                cout << "Bug!" << endl;
                return 0;
            }
            else {
                v[tempy][tempx] = '.';
            }
        }
    }

    if(v[y][x] == 'D') {
        cout << "Diamond!" << endl;
    }
    else {
        cout << "Bug!" << endl;
    }
}
