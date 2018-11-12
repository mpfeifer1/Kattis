#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();

    set<vector<int>> s;
    for(int i = 0; i < n; i++) {
        vector<int> v(26,0);
        for(int j = i; j < n; j++) {
            v[s2[j]-'a']++;
            s.insert(v);
        }
    }

    int lo = 0;
    int hi = -1;

    for(int i = 0; i < n; i++) {
        vector<int> v(26,0);
        for(int j = i; j < n; j++) {
            v[s1[j]-'a']++;
            if(s.count(v)) {
                if(j-i > hi-lo) {
                    lo = i;
                    hi = j;
                }
            }
        }
    }

    if(hi == -1) {
        cout << "NONE" << endl;
    }
    else {
        for(int i = lo; i <= hi; i++) {
            cout << s1[i];
        }
        cout << endl;
    }
}

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        solve();
    }
}
