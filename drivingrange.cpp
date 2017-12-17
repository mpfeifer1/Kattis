#include <bits/stdc++.h>

using namespace std;

int find(vector<int>& d, int a) {
    if(d[a] == -1) {
        return a;
    }
    d[a] = find(d, d[a]);
    return d[a];
}

void join(vector<int>& d, int a, int b) {
    a = find(d, a);
    b = find(d, b);

    if(a == b) {
        return;
    }

    d[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int,int>>> v;
    for(int i = 0; i < m; i++) {
        int n1, n2, w;
        cin >> n1 >> n2 >> w;
        v.push_back({w, {n1,n2}});
    }

    sort(v.begin(), v.end());

    int best = 0;
    vector<int> d(n, -1);
    for(auto i : v) {
        if(find(d, i.second.first) != find(d, i.second.second)) {
            join(d, i.second.first, i.second.second);
            best = max(best, i.first);
        }
    }

    for(int i = 1; i < d.size(); i++) {
        if(find(d, i-1) != find(d, i)) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    cout << best << endl;
}
