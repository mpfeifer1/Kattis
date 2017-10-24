#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int find(vector<int>& disjoint, int a) {
    if(disjoint[a] == -1) {
        return a;
    }

    disjoint[a] = find(disjoint, disjoint[a]);
    return disjoint[a];
}

void join(vector<int>& disjoint, int a, int b) {
    a = find(disjoint, a);
    b = find(disjoint, b);

    if(a == b) {
        return;
    }

    disjoint[a] = b;
}

int linear(int row, int col, int r, int c) {
    return row * c + col;
}

bool inrange(int x, int y, int r, int c) {
    return x >= 0 && y >= 0 && x < r && y < c;
}

int main() {
    int r, c;
    cin >> r >> c;

    // Map each number to a list of its locations
    unordered_map<int, vector<pair<int, int>>> locs;
    vector<vector<int>> v;
    vector<int> all;
    v.resize(r, vector<int>(c));

    // Take in input
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            int num;
            cin >> num;

            all.push_back(num);
            v[i][j] = num;

            locs[num].push_back({i, j});
        }
    }

    // Set up disjoint set
    vector<int> disjoint(r*c+2, -1);

    int left = disjoint.size()-1;
    int right = disjoint.size()-2;

    for(int i = 0; i < r; i++) {
        // Attach top row to top point
        join(disjoint, left, linear(i, 0, r, c));

        // Attach bot row to bot point
        join(disjoint, right, linear(i, c-1, r, c));
    }

    // Sort all the points (so the lowest is at the back)
    sort(all.rbegin(), all.rend());
    auto it = unique(all.begin(), all.end());
    all.resize(distance(all.begin(), it));

    // Keep adding points until it becomes connected
    int depth = 0;
    while(all.size() > 0 && find(disjoint, left) != find(disjoint, right)) {
        depth = all.back();
        all.pop_back();

        for(auto loc : locs[depth]) {
            int x = loc.first;
            int y = loc.second;

            if(inrange(x-1, y, r, c) && v[x-1][y] <= v[x][y]) {
                join(disjoint, linear(x-1, y, r, c), linear(x, y, r, c));
            }
            if(inrange(x+1, y, r, c) && v[x+1][y] <= v[x][y]) {
                join(disjoint, linear(x+1, y, r, c), linear(x, y, r, c));
            }
            if(inrange(x, y-1, r, c) && v[x][y-1] <= v[x][y]) {
                join(disjoint, linear(x, y-1, r, c), linear(x, y, r, c));
            }
            if(inrange(x, y+1, r, c) && v[x][y+1] <= v[x][y]) {
                join(disjoint, linear(x, y+1, r, c), linear(x, y, r, c));
            }
        }
    }

    cout << depth << endl;
}
