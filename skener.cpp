#include <iostream>
#include <vector>

using namespace std;

int main() {
    int r, c, x, y;
    cin >> r >> c >> x >> y;

    vector<vector<char>> v;
    v.resize(r);
    for(auto &row : v) {
        row.resize(c);
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> v[i][j];
        }
    }

    for(int i = 0; i < r * x; i++) {
        for(int j = 0; j < c * y; j++) {
            cout << v[i/x][j/y];
        }
        cout << endl;
    }
    cout << endl;
}
