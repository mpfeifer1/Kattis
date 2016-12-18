#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<char>> map;
    int i, j;
    cin >> i >> j;

    map.resize(i);
    for(int a = 0; a < i; a++) {
        for(int b = 0; b < j; b++) {
            char temp;
            cin >> temp;
            map[a].push_back(temp);
        }
    }

    int x = 0, y = 0, moves = 0;
    while(true) {
        if(x < 0 || y < 0 || x >= i || y >= j) {
            cout << "Out" << endl;
            return 0;
        }
        if(moves > i * j * 2) {
            cout << "Lost" << endl;
            return 0;
        }
        if(map[x][y] == 'T') {
            cout << moves << endl;
            return 0;
        }
        else if(map[x][y] == 'E') {
            y++;
        }
        else if(map[x][y] == 'W') {
            y--;
        }
        else if(map[x][y] == 'N') {
            x--;
        }
        else if(map[x][y] == 'S') {
            x++;
        }
        moves++;
    }
}
