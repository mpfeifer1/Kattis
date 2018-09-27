#include <bits/stdc++.h>

using namespace std;

int find(vector<int>& d, int a) {
    if(d[a] == -1) return a;
    return d[a] = find(d, d[a]);
}

void join(vector<int>& d, int a, int b) {
    a = find(d, a);
    b = find(d, b);
    if(a == b) return;
    d[a] = b;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> d(n,-1);
    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        join(d,n1,n2);
    }

    int cc = 0;
    for(int i = 0; i < n; i++) {
        if(d[i] == -1) cc++;
    }

    cout << cc-1 << endl;
}

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        solve();
    }
}
