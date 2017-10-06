#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // Take in input
    double cap;
    int items;
    while(cin >> cap && cin >> items) {
        int capacity = floor(cap);

        // Create the memo table
        vector<vector<int>> v;
        v.resize(items+1, vector<int>(capacity+1, 0));

        // Take in all the items
        vector<pair<int, int>> objects;
        objects.push_back({0,0});
        for(int i = 0; i < items; i++) {
            pair<int, int> p;
            cin >> p.first >> p.second;
            objects.push_back(p);
        }

        for(int i = 1; i < objects.size(); i++) {
            pair<int, int> object = objects[i];
            for(int j = 1; j <= capacity; j++) {
                // If we can't take this item, continue
                if(j < object.second) {
                    v[i][j] = v[i-1][j];
                    continue;
                }

                v[i][j] = max(v[i-1][j-object.second] + object.first, v[i-1][j]);
            }
        }

        for(int i = 0; i <= items; i++) {
            for(int j = 0; j <= capacity; j++) {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }

        cout << v[items][capacity] << endl;
    }
}
