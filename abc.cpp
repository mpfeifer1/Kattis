#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    vector<int> v;
    v.resize(3);

    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());

    string s;
    cin >> s;

    if(s == "ABC") {
        cout << v[0] << " " << v[1] << " " << v[2] << endl;
    }
    if(s == "ACB") {
        cout << v[0] << " " << v[2] << " " << v[1] << endl;
    }
    if(s == "BAC") {
        cout << v[1] << " " << v[0] << " " << v[2] << endl;
    }
    if(s == "BCA") {
        cout << v[1] << " " << v[2] << " " << v[0] << endl;
    }
    if(s == "CAB") {
        cout << v[2] << " " << v[0] << " " << v[1] << endl;
    }
    if(s == "CBA") {
        cout << v[2] << " " << v[1] << " " << v[0] << endl;
    }
}
