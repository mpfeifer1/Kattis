#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> cubes;
    for(int i = 1; i*i*i <= n; i++) {
        cubes.push_back(i*i*i);
    }

    map<int,int> sums;
    for(int i = 0; i < cubes.size(); i++) {
        for(int j = i+1; j < cubes.size(); j++) {
            sums[cubes[i]+cubes[j]]++;
        }
    }

    int best = -1;
    for(auto i : sums) {
        if(i.second > 1 && i.first <= n) {
            best = i.first;
        }
    }

    if(best == -1) {
        cout << "none" << endl;
    }
    else {
        cout << best << endl;
    }
}
