#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool charcomp(string i, string j) {
    for(auto& c : i) {
        c = tolower(c);
    }
    for(auto& c : j) {
        c = tolower(c);
    }

    return i < j;
}

int main() {
    int r, c;
    while(cin >> r && cin >> c && r != 0 && c != 0) {
        vector<string> v;
        v.resize(c, "");
        for(int j = 0; j < r; j++) {
            for(int i = 0; i < c; i++) {
                char temp;
                cin >> temp;
               v[i].push_back(temp);
            }
        }

        stable_sort(v.begin(), v.end(), charcomp);

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                cout << v[j][i];
            }
            cout << endl;
        }
        cout << endl;
    }
}
