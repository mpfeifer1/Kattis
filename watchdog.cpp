#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool inrange(int i, int j, int leash, pair<int, int> h) {
    double dist = sqrt(pow(abs(i-h.first), 2) + pow(abs(j-h.second), 2));
    return dist <= leash;
}

int main() {
    int cases;
    cin >> cases;

    while(cases--) {
        int size, count;
        cin >> size >> count;

        vector<pair<int, int>> hatches;
        for(int i = 0; i < count; i++) {
            pair<int, int> hatch;
            cin >> hatch.first >> hatch.second;
            hatches.push_back(hatch);
        }

        bool found = false;
        int xloc;
        int yloc;
        for(int i = 1; i < size && !found; i++) {
            for(int j = 1; j < size && !found; j++) {
                int leash = min(min(i, size-i), min(j, size-j));

                bool works = true;
                for(auto h : hatches) {
                    if(h.first == i && h.second == j) {
                        works = false;
                    }
                    if(!inrange(i, j, leash, h)) {
                        works = false;
                    }
                }

                if(works) {
                    found = true;
                    xloc = i;
                    yloc = j;
                }
            }
        }

        if(found) {
            cout << xloc << " " << yloc << endl;
        }
        else {
            cout << "poodle" << endl;
        }
    }
}
