#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int r, c;
    cin >> r >> c;

    // Input array
    vector<vector<char>> v;
    v.resize(r, vector<char>(c));
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> v[i][j];
        }
    }

    // transpose array
    vector<vector<char>> t;
    t.resize(c, vector<char>(r));
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            t[j][i] = v[i][j];
        }
    }

    // sort each, splitting on '#'
    for(auto& i : t) {
        vector<int> obstacles;
        obstacles.push_back(-1);
        for(int k = 0; k < i.size(); k++) {
            if(i[k] == '#') {
                obstacles.push_back(k);
            }
        }
        obstacles.push_back(i.size());

        for(int l = 0; l < obstacles.size()-1; l++) {
            sort(i.begin()+obstacles[l]+1, i.begin()+obstacles[l+1]);
        }
    }

    // transpose back
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            v[i][j] = t[j][i];
        }
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << v[i][j];
        }
        cout << endl;
    }
}
