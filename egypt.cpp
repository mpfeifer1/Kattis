#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v(3);
    while(true) {
        for(auto& i : v) {
            cin >> i;
        }
        if(v[0] == 0 && v[1] == 0 && v[2] == 0) {
            return 0;
        }


        sort(v.begin(), v.end());

        if(v[0] * v[0] + v[1] * v[1] == v[2] * v[2]) {
            cout << "right" << endl;
        }
        else {
            cout << "wrong" << endl;
        }
    }
}
