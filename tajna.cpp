#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    string s;
    cin >> s;

    int size = s.size();
    int rows = sqrt(size);

    while(size % rows != 0) {
        rows--;
    }

    int cols = size / rows;
    swap(rows, cols);

    vector<vector<char>> v;
    v.resize(rows, vector<char>(cols));

    int n = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            v[i][j] = s[n];
            n++;
        }
    }

    for(int j = 0; j < cols; j++) {
        for(int i = 0; i < rows; i++) {
            cout << v[i][j];
        }
    }
    cout << endl;
}
