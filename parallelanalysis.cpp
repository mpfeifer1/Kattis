#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int best = 0;
    unordered_map<int,int> m;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        int besthere = 0;
        int v;
        for(int j = 0; j < t-1; j++) {
            cin >> v;
            besthere = max(besthere, m[v]);
        }
        cin >> v;
        besthere++;
        m[v] = besthere;
        best = max(best, besthere);
    }

    cout << best << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int cases;
    cin >> cases;
    for(int i = 1; i <= cases; i++) {
        cout << i << " ";
        solve();
    }
}
