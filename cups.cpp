#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> v;
    v.resize(2500, "");

    for(int i = 0; i < n; i++) {
        int size;
        string color;

        cin.ignore();
        if(isalpha(cin.peek())) {
            cin >> color;
            cin >> size;
            size *= 2;
        }
        else {
            cin >> size;
            cin >> color;
        }

        v[size] = color;
    }

    for(int i = 0; i < v.size(); i++) {
        if(v[i] != "") {
            cout << v[i] << endl;
        }
    }
}
