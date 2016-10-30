#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int times;
    cin >> times;
    for(int i = 0; i < times; i++) {
        // Read in ants
        int l, ants;
        cin >> l >> ants;
        vector<int> a;
        for(int i = 0; i < ants; i++) {
            int ant;
            cin >> ant;
            a.push_back(ant);
        }

        // Sort Ants
        sort(a.begin(), a.end());

        // Find Center Ant
        double center = 10000000;
        int centerA = 0;
        for(int i = 0; i < ants; i++) {
            if(abs(a[i] - l/2) < center) {
                center = abs(a[i] - l/2);
                centerA = i; 
            }
        }

        // Print minimum distance for center ant
        if(a[centerA] < l-a[centerA]) {
            cout << a[centerA] << " ";
        }
        else {
            cout << l-a[centerA] << " ";
        }

        // Calculate length of board - ant closest to end
        if(l-a[0] < a[ants-1]) {
            cout << a[ants-1] << endl;
        }
        else {
            cout << l-a[0] << endl;
        }
    }
}
