#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    map<string,int> m;
    for(int i = 0; i < n; i++) {
        string s;
        int t;
        cin >> s >> t;

        m[s] += t;
    }

    vector<pair<int,string>> v;
    for(auto i : m) {
        v.push_back({-i.second, i.first});
    }

    sort(v.begin(), v.end());

    cout << v.size() << endl;
    for(auto i : v) {
        cout << i.second << " " << -i.first << endl;
    }
}

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        solve();
    }
}
