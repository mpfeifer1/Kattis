#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printwhack(vector<string>& v, int i, int j, int side) {
    // Create the sides
    for(int k = 0; k < side; k++) {
        v[i][j+k] = '-';
        v[i+side-1][j+k] = '-';
        v[i+k][j] = '|';
        v[i+k][j+side-1] = '|';
    }

    // Create the corners
    v[i][j] = '+';
    v[i+side-1][j] = '+';
    v[i][j+side-1] = '+';
    v[i+side-1][j+side-1] = '+';
}

int whack(vector<string>& v, int i, int j, int side) {
    int total = 0;
    for(int k = 1; k < side-1; k++) {
        for(int l = 1; l < side-1; l++) {
            if(v[i+k][l+j] == '*') {
                total++;
            }
        }
    }
    return total;
}

int main() {
    int h, w, side;
    cin >> h >> w >> side;

    vector<string> v;
    for(int i = 0; i < h; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    int m = -1;
    int max_i = -1;
    int max_j = -1;

    for(int i = 0; i < h-side+1; i++) {
        for(int j = 0; j < w-side+1; j++) {
            int thiswhack = whack(v, i, j, side);
            if(thiswhack > m) {
                m = thiswhack;
                max_i = i;
                max_j = j;
            }
        }
    }

    printwhack(v, max_i, max_j, side);

    cout << m << endl;
    for(auto i : v) {
        cout << i << endl;
    }
}
