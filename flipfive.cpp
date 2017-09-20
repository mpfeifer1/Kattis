#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int board_to_num(vector<vector<char>>& v) {
    int total = 0;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(v[i][j] == '*') {
                total += pow(2, (i*3)+j);
            }
        }
    }

    return total;
}

void charswap(vector<vector<char>>& v, int i, int j) {
    if(i < 0 || i >= 3 || j < 0 || j >= 3) {
        return;
    }
    if(v[i][j] == '.') {
        v[i][j] = '*';
    }
    else {
        v[i][j] = '.';
    }
}

void swapall(vector<vector<char>>& v, int i, int j) {
    charswap(v, i,   j);
    charswap(v, i+1, j);
    charswap(v, i-1, j);
    charswap(v, i,   j+1);
    charswap(v, i,   j-1);
}

void fill(vector<vector<char>>& v, vector<int>& score, int i, int j, int dist) {
    swapall(v, i, j);
    int state = board_to_num(v);

    if(score[state] <= dist) {
        swapall(v, i, j);
        return;
    }

    score[state] = dist;
    for(int k = 0; k < 3; k++) {
        for(int l = 0; l < 3; l++) {
            fill(v, score, k, l, dist+1);
        }
    }

    swapall(v, i, j);
}

void fill_board(vector<vector<char>>& v, vector<int>& score) {
    score[0] = 0;
    for(int k = 0; k < 3; k++) {
        for(int l = 0; l < 3; l++) {
            fill(v, score, k, l, 1);
        }
    }
}

int main() {
    int n;
    cin >> n;

    // Set up the memory
    vector<vector<char>> v;
    v.resize(3, vector<char>(3, '.'));

    // Fill in the distance for each position
    vector<int> score;
    score.resize(512, 10000);
    fill_board(v, score);

    // Take in the data, get the distance
    for(int i = 0; i < n; i++) {
        // Read in the array
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                cin >> v[j][k];
            }
        }

        int dist = score[board_to_num(v)];
        cout << dist << endl;
    }
}
