#include <bits/stdc++.h>
using namespace std;

#define int long long

bool cmp(pair<int, int> x, pair<int, int> y) {
    if(x.first*y.second == y.first*x.second) {
        return x.first < y.first;
    }
    return x.first*y.second < y.first*x.second;
}

signed main() {
    int f, b;
    cin >> f >> b;
    vector<int> F(f), B(b);
    for(int i = 0; i < f; ++i) {
        cin >> F[i];
    }
    for(int i = 0; i < b; ++i) {
        cin >> B[i];
    }
    vector<pair<int, int>> arr;
    for(int i = 0; i < f; ++i) {
        for(int j = 0; j < b; ++j) {
            arr.push_back({F[i], B[j]});
        }
    }
    sort(arr.begin(), arr.end(), cmp);
    for(auto &p : arr) {
        cout << '(' << p.first << ',' << p.second << ")\n";
    }
}
