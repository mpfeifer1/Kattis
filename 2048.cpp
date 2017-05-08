#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> board;

vector<int> swipe(vector<int> v) {

    // Get only non-zero elements
    vector<int> v2;
    for(int i = 0; i < 4; i++) {
        if(v[i] != 0) {
            v2.push_back(v[i]);
        }
    }

    // Add 0 to the end so that the last element won't double
    v2.push_back(0);

    // Merge together, left is merged, right is zero
    for(int i = 0; i < v2.size(); i++) {
        if(v2[i] == v2[i+1]) {
            v2[i] *= 2;
            v2[i+1] = 0;
        }
    }

    // Slide left
    vector<int> v3;
    for(int i = 0; i < v2.size(); i++) {
        if(v2[i] != 0) {
            v3.push_back(v2[i]);
        }
    }

    // Fill with zeroes
    int blanks = 4 - v3.size();
    for(int i = 0; i < blanks; i++) {
        v3.push_back(0);
    }

    return v3;
}



int main() {
    // Initialize board
    board.resize(4);
    board[0].resize(4);
    board[1].resize(4);
    board[2].resize(4);
    board[3].resize(4);

    // Input board
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> board[i][j];
        }
    }

    int dir;
    cin >> dir;



    // Swipe each row/col
    if(dir == 0) {
        // Left
        for(int i = 0; i < 4; i++) {
            board[i] = swipe(board[i]);
        }
    }
    if(dir == 1) {
        // Up
        for(int i = 0; i < 4; i++) {
            vector<int> v;
            v.resize(4);
            v[0] = board[0][i];
            v[1] = board[1][i];
            v[2] = board[2][i];
            v[3] = board[3][i];
            v = swipe(v);
            board[0][i] = v[0];
            board[1][i] = v[1];
            board[2][i] = v[2];
            board[3][i] = v[3];
        }
    }
    if(dir == 2) {
        // Right
        for(int i = 0; i < 4; i++) {
            reverse(board[i].begin(), board[i].end());
            board[i] = swipe(board[i]);
            reverse(board[i].begin(), board[i].end());
        }
    }
    if(dir == 3) {
        // Down
        for(int i = 0; i < 4; i++) {
            vector<int> v;
            v.resize(4);
            v[3] = board[0][i];
            v[2] = board[1][i];
            v[1] = board[2][i];
            v[0] = board[3][i];
            v = swipe(v);
            board[0][i] = v[3];
            board[1][i] = v[2];
            board[2][i] = v[1];
            board[3][i] = v[0];
        }
    }



    // Output board
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
