#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int parent(vector<int>& v, int n) {
    // If this is the representative, return it
    if(v[n] == -1) {
        return n;
    }

    // Otherwise set this one's representative, and return
    v[n] = parent(v, v[n]);
    return v[n];
}

void join(vector<int>& v, int a, int b) {
    int p1 = parent(v, a);
    int p2 = parent(v, b);

    // Same number
    if(p1 == p2) {
        return;
    }

    // Both representative
    if(v[p1] < 0 && v[p2] < 0) {
        v[p1] = p2;
        return;
    }

    // B representative
    if(v[p1] >= 0 && v[p2] < 0) {
        v[p1] = p2;
    }

    // A representative
    if(v[p1] < 0 && v[p2] >= 0) {
        v[p2] = p1;
    }
}

int main() {
    int houses, conns;
    cin >> houses >> conns;

    // Set up the disjoint set
    vector<int> v;
    v.resize(houses+1, -1);

    // Join all the houses together
    for(int i = 0; i < conns; i++) {
        int h1, h2;
        cin >> h1 >> h2;

        join(v, h1, h2);
    }

    // Print all houses not connected to 1
    bool printed = false;
    int rep = parent(v, 1);
    for(int i = 2; i <= houses; i++) {
        if(parent(v, i) != rep) {
            printed = true;
            cout << i << endl;
        }
    }

    // If all houses connected, print that instead
    if(!printed) {
        cout << "Connected" << endl;
    }
}
