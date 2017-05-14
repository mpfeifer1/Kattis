#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    vector<int> v;
    string s;

    int m = 0;
    while(getline(cin,s)) {
        int temp = s.length();
        m = max(temp, m);
        v.push_back(temp);
    }

    int total = 0;
    for(int i = 0; i < v.size() - 1; i++) {
        total += pow(abs(m-v[i]), 2);
    }

    cout << total << endl;
}
