#include <bits/stdc++.h>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    string a1, a2;

    for(auto i : s1) {
        a1.push_back(i);
        a1.push_back('.');
    }
    a1.pop_back();

    for(auto i : s2) {
        a2.push_back(i);
        a2.push_back('.');
    }
    a2.pop_back();

    vector<int> diff;

    for(int i = 0; i < a1.size(); i++) {
        if(a1[i] != a2[i]) {
            diff.push_back(i);
        }
    }

    if(diff.size() % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }

    // Diff's size should be 2+
    int center = (diff.front() + diff.back()) / 2;

    // Iterate out from center to check if valid
    int l = center;
    int r = center;

    while(true) {
        if(a1[l] == a2[r] && a1[r] == a2[l]) {
            l--;
            r++;
        }
        else {
            break;
        }

        if(l < 0 || r >= a1.size()) {
            break;
        }
    }

    l++;
    r--;

    if(l > diff.front() || r < diff.back()) {
        cout << 0 << endl;
        return 0;
    }

    int ways = 0;
    for(int i = l; i <= diff.front(); i++) {
        if(a1[i] != '.') ways++;
    }

    cout << ways << endl;
}
