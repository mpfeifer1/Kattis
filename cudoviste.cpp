#include <iostream>
#include <vector>

using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<char>> v;
    for(int i = 0; i < r; i++) {
        vector<char> temp;
        for(int j = 0; j < c; j++) {
            char character;
            cin >> character;
            temp.push_back(character);
        }
        v.push_back(temp);
    }

    vector<int> ans = {0, 0, 0, 0, 0};

    for(int i = 0; i < r-1; i++) {
        for(int j = 0; j < c-1; j++) {
            int cars = 0;

            // Count how many cars are squished
            if(v[i][j] == 'X') {
                cars++;
            }
            if(v[i+1][j] == 'X') {
                cars++;
            }
            if(v[i][j+1] == 'X') {
                cars++;
            }
            if(v[i+1][j+1] == 'X') {
                cars++;
            }

            // Check if a building is in the way
            if(v[i][j] == '#') {
                continue;
            }
            if(v[i+1][j] == '#') {
                continue;
            }
            if(v[i][j+1] == '#') {
                continue;
            }
            if(v[i+1][j+1] == '#') {
                continue;
            }

            // Increment the answer vector
            ans[cars]++;
        }
    }

    for(auto i : ans) {
        cout << i << endl;
    }
}
