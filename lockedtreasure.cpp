#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> v;
    v.resize(31, vector<int>(31, 1));

    for(int i = 2; i <= 30; i++) {
        for(int j = 2; j <= i; j++) {
            v[i][j] = v[i-1][j] + v[i-1][j-1];
        }
    }

    int cases;
    cin >> cases;

    for(int i = 0; i < cases; i++) {
        int pirates, groups;
        cin >> pirates >> groups;
        cout << v[pirates][groups] << endl;
    }
}
