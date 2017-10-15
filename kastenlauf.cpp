#include <iostream>
#include <vector>

using namespace std;

bool close(vector<pair<int, int>>& v, int i, int j) {
    int dist = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
    return dist <= 1000;
}

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

int main() {
    int cases;
    cin >> cases;

    while(cases--) {
        // Read in input
        int stores;
        cin >> stores;
        stores += 2;
        vector<pair<int, int>> v;
        for(int i = 0; i < stores; i++) {
            pair<int, int> p;
            cin >> p.first >> p.second;
            v.push_back(p);
        }

        // Set up the disjoint set
        vector<int> disjoint(stores, -1);

        // For each combination of points
        for(int i = 0; i < stores-1; i++) {
            for(int j = i; j < stores; j++) {
                if(close(v, i, j)) {
                    join(disjoint, i, j);
                }
            }
        }

        // Check if his house connects
        int home = find(disjoint, 0);
        int berg = find(disjoint, stores-1);
        if(home == berg) {
            cout << "happy" << endl;
        }
        else {
            cout << "sad" << endl;
        }
    }
}
