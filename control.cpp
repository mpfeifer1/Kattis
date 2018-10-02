#include <bits/stdc++.h>

using namespace std;

int find(vector<int>& d, int a) {
    if(d[a] < 0) return a;
    return d[a] = find(d, d[a]);
}

void join(vector<int>& d, int a, int b) {
    a = find(d, a);
    b = find(d, b);
    if(a == b) return;
    d[a] += d[b];
    d[b] = a;
}

int size(vector<int>& d, int a) {
    a = find(d, a);
    return -d[a];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<int> d(500001,-1);

    int n;
    cin >> n;

    int ans = 0;
    while(n--) {
        int t;
        cin >> t;

        set<int> par;
        vector<int> all(t);
        for(auto& i : all) {
            cin >> i;
            i = find(d, i);
            par.insert(i);
        }

        int total = 0;
        for(auto i : par) {
            total += size(d, i);
        }

        if(total == t) {
            ans++;
            for(int i = 1; i < all.size(); i++) {
                join(d, all[0], all[i]);
            }
        }
    }

    cout << ans << endl;
}
