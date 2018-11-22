#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
ld inf = (ld)1000000000000;

int main() {
    int n;
    cin >> n;
    vector<pair<ld,ld>> v(n);
    for(auto& i : v) {
        cin >> i.first >> i.second;
    }

    sort(v.begin(),v.end());

    ld best = -inf;
    for(int i = 1; i < n; i++) {
        ld bot = v[i].first - v[i-1].first;
        ld top = v[i].second - v[i-1].second;
        best = max(best, abs(top / bot));
    }

    cout << fixed;
    cout.precision(12);
    cout << best << endl;
}
