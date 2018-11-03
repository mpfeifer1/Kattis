#include <bits/stdc++.h>

using namespace std;

void solve(int n) {
    vector<int> v(n);
    vector<int> pos(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        pos[v[i]] = i;
    }

    for(int s = 0; s < n; s++) {
        for(int d = -n; d <= n; d++) {
            if(s+d+d >= 0 && s+d+d < n) {
                if(pos[s] < pos[s+d] && pos[s+d] < pos[s+d+d]) {
                    cout << "no" << endl;
                    return;
                }
            }
        }
    }

    cout << "yes" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    while(cin >> n && n != 0) {
        cin.ignore();
        solve(n);
    }
}
