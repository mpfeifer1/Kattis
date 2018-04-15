#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    map<string,int> m;

    for(int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;

        m[s2]++;
    }

    int ans = 1;
    for(auto i : m) {
        ans *= i.second + 1;
    }

    cout << ans - 1 << endl;
}

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        solve();
    }
}
