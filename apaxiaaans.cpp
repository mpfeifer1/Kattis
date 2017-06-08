#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string name;
    cin >> name;

    string::iterator it;
    it = unique(name.begin(), name.end());
    name.resize(distance(name.begin(), it));

    cout << name << endl;
}
