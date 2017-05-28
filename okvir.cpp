#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;

    int u, l, r, d;
    cin >> u >> l >> r >> d;

    vector<vector<char>> v;
    v.resize(rows + u + d);
    for(auto& row : v) {
        row.resize(cols + l + r, '#');
    }

    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) {
            //v[i][j] = '#';
            if((i+j) % 2 == 1) {
                v[i][j] = '.';
            }
        }
    }

    vector<string> s;
    for(int i = 0; i < rows; i++) {
        string temp;
        cin >> temp;
        s.push_back(temp);
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            v[i+u][j+l] = s[i][j];
        }
    }

    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) {
            cout << v[i][j];
        }
        cout << endl;
    }
}
