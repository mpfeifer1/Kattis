#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_set<string> seen;

    int count = 0;
    for(int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;

        if(seen.count(s1) == 0 && count < 12) {
            cout << s1 << " " << s2 << endl;
            count++;
        }
        seen.insert(s1);
    }
}
