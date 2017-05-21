#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // Fill Strings
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> v1, v2, v3;

    // Convert To Vector
    for(auto c : s1) {
        v1.push_back(c - '0');
    }

    for(auto c : s2) {
        v2.push_back(c - '0');
    }

    // Calculate Size
    int size = max(v1.size(), v2.size()) + 1;
    v3.resize(size, 0);

    // Pad with Zeroes
    while(v1.size() < v3.size()) {
        v1.insert(v1.begin(), 0);
    }
    while(v2.size() < v3.size()) {
        v2.insert(v2.begin(), 0);
    }

    // Add together
    for(int i = 0; i < v1.size(); i++) {
        v3[i] += v1[i];
    }

    for(int i = 0; i < v2.size(); i++) {
        v3[i] += v2[i];
    }

    // Make sure no overflow
    for(int i = v3.size()-1; i >= 0; i--) {
        if(v3[i] >= 10) {
            v3[i] -= 10;
            v3[i-1]++;
        }
    }

    if(v3[0] == 0) {
        v3.erase(v3.begin());
    }

    // Print
    for(auto c : v3) {
        cout << c;
    }
    cout << endl;
}
