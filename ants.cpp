#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;

    while(cases--) {
        int n, m;
        cin >> n >> m;

        vector<int> v(m);
        for(auto& i : v) {
            cin >> i;
        }

        int lo = min(v[0], n-v[0]);
        int hi = max(v[0], n-v[0]);

        for(auto i : v) {
            lo = max(lo, min(i, n-i));
            hi = max(hi, max(i, n-i));
        }

        cout << lo << " " << hi << endl;
    }
}
