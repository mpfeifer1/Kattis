#include <bits/stdc++.h>

using namespace std;

int main() {
    map<char,int> m;
    string s;
    while(cin >> s) {
        m[s[0]]++;
    }

    int best = 0;
    for(auto i : m) {
        best = max(best, i.second);
    }

    cout << best << endl;
}
