#include <iostream>
#include <vector>

using namespace std;

bool valid(vector<vector<char>> v, int i, int j) {
    if(i < 0 || j < 0 || i > 6 || j > 6) {
        return false;
    }

    if(v[i][j] == 'o') {
        return true;
    }

    return false;
}

int main() {
    vector<vector<char>> v;
    v.resize(7);
    for(int i = 0; i < 7; i++) {
        v[i].resize(7, ' ');
    }

    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < 7; j++) {
            cin.get(v[i][j]);
        }
        cin.ignore();
    }

    int total = 0;
    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < 7; j++) {
            if(v[i][j] == '.') {
                if(valid(v, i+2, j) && valid(v, i+1, j)) {
                    total++;
                }
                if(valid(v, i-2, j) && valid(v, i-1, j)) {
                    total++;
                }
                if(valid(v, i, j+2) && valid(v, i, j+1)) {
                    total++;
                }
                if(valid(v, i, j-2) && valid(v, i, j-1)) {
                    total++;
                }
            }
        }
    }

    cout << total << endl;
}
