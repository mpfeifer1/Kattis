#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int w, p;
    cin >> w >> p;

    vector<int> walls;
    walls.push_back(0);

    for(int i = 0; i < p; i++) {
        int temp;
        cin >> temp;
        walls.push_back(temp);
    }

    walls.push_back(w);

    vector<int> possible;

    // i is number of sections you're using
    for(int i = 1; i < p+2; i++) {
        // j is starting section number
        for(int j = 0; j < p + 2 - i; j++) {
            possible.push_back(walls[j+i] - walls[j]);
        }
    }

    sort(possible.begin(), possible.end());

    vector<int>::iterator it;
    it = unique(possible.begin(), possible.end());
    possible.resize(distance(possible.begin(), it));

    for(auto i : possible) {
        cout << i << " ";
    }
    cout << endl;
}
