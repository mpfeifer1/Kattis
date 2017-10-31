#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;
    v.push_back(1);

    while(v.back() < n) {
        v.push_back(v.back()*2);
    }

    while(v.back() > n) {
        v.pop_back();
    }

    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
