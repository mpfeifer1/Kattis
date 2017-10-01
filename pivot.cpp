#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;
    vector<int> c_max;
    vector<int> c_min;

    v.resize(n);
    c_max.resize(n);
    c_min.resize(n);

    // Take in the data
    for(auto& i : v) {
        cin >> i;
    }

    // Calculate max from left
    c_max[0] = v[0];
    for(int i = 1; i < v.size(); i++) {
        c_max[i] = max(v[i], c_max[i-1]);
    }

    // Calculate min from right
    c_min[n-1] = v[n-1];
    for(int i = n-2; i >= 0; i--) {
        c_min[i] = min(v[i], c_min[i+1]);
    }

    // Count edge pivots
    int total = 0;
    if(v[0] < c_min[1]) {
        total++;
    }
    if(v[n-1] > c_min[n-2]) {
        total++;
    }

    // Count center pivots
    for(int i = 1; i < n-1; i++) {
        if(v[i] < c_min[i+1] && v[i] > c_max[i-1]) {
            total++;
        }
    }

    // Print answer
    cout << total << endl;
}
