#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<char>> v;
    v.resize(9, vector<char>(9, '.'));

    for(int i = 2; i < 7; i++) {
        for(int j = 2; j < 7; j++) {
            cin >> v[i][j];
        }
    }

    bool valid = true;
    int total = 0;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(v[i][j] == 'k') {
                total++;

                if(v[i+2][j+1] == 'k') {
                    valid = false;
                }
                if(v[i+2][j-1] == 'k') {
                    valid = false;
                }
                if(v[i-2][j+1] == 'k') {
                    valid = false;
                }
                if(v[i-2][j-1] == 'k') {
                    valid = false;
                }
                if(v[i+1][j+2] == 'k') {
                    valid = false;
                }
                if(v[i+1][j-2] == 'k') {
                    valid = false;
                }
                if(v[i-1][j+2] == 'k') {
                    valid = false;
                }
                if(v[i-1][j-2] == 'k') {
                    valid = false;
                }

            }
        }
    }

    if(total != 9) {
        valid = false;
    }

    if(valid) {
        cout << "valid" << endl;
    }
    else {
        cout << "invalid" << endl;
    }
}
