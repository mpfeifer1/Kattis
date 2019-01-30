#include <bits/stdc++.h>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int ki, kj;
    bool broken = false;
    for(int i = 0; i < s1.size(); i++) {
        for(int j = 0; j < s2.size(); j++) {
            if(s1[i] == s2[j]) {
                ki = i;
                kj = j;
                broken = true;
                break;
            }
        }
        if(broken) {
            break;
        }
    }

    vector<vector<char>> v(s1.size(), vector<char>(s2.size(), '.'));

    for(int i = 0; i < s1.size(); i++) {
        v[i][kj] = s1[i];
    }

    for(int j = 0; j < s2.size(); j++) {
        v[ki][j] = s2[j];
    }

    for(int j = 0; j < s2.size(); j++) {
        for(int i = 0; i < s1.size(); i++) {
            cout << v[i][j];
        }
        cout << endl;
    }
}
