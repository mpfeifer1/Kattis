#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int find_islands(vector<int> v) {
    // Sink the whole range
    int minimum = v[0];
    for(int i = 0; i < v.size(); i++) {
        minimum = min(minimum, v[i]);
    }
    for(int i = 0; i < v.size(); i++) {
        v[i] -= minimum;
    }

    // Check that there's a non-zero element
    bool nonzero = false;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] != 0) {
            nonzero = true;
        }
    }
    if(!nonzero) {
        return 0;
    }

    // Start new array of islands
    vector<vector<int>> newislands;
    vector<int> filler;
    newislands.push_back(filler);

    // Fill array of islands
    for(int i = 0; i < v.size(); i++) {
        if(v[i] == 0) {
            vector<int> temp;
            newislands.push_back(temp);
        }
        else {
            newislands[newislands.size()-1].push_back(v[i]);
        }
    }

    // Count the islands
    int total = 0;
    for(auto i : newislands) {
        if(!i.empty()) {
            total += 1;
            total += find_islands(i);
        }
    }

    return total;
}

int main() {
    int cases;
    cin >> cases;

    for(int i = 1; i <= cases; i++) {
        cin >> i;

        vector<int> v;
        v.resize(12);
        for(int j = 0; j < 12; j++) {
            cin >> v[j];
        }

        cout << i << " " << find_islands(v) << endl;
    }
}
