#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

pair<int, int> find(vector<vector<int>> v, int key) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(v[i][j] == key) {
                return {i, j};
            }
        }
    }

    return {0,0};
}

double distance(pair<int, int> a, pair<int, int> b) {
    double d = 0;
    d += pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
    d = sqrt(d);
    return d;
}

int main() {
    vector<vector<int>> v;
    v.resize(3, vector<int>(3));

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> v[i][j];
        }
    }

    double dist = 0;
    for(int i = 1; i <= 8; i++) {
        dist += distance(find(v, i), find(v, i+1));
    }

    cout.precision(10);
    cout << fixed;
    cout << dist << endl;
}
