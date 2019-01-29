#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    int resolved = 0;
    vector<int> ct(m+1,0);

    for(int i = 0; i < m; i++) {
        // Add the next song to the set list
        for(int j = 0; j < n; j++) {
            ct[v[j][i]]++;
            if(ct[v[j][i]] == n) {
                resolved++;
            }
        }
        if(resolved == i+1) {
            break;
        }
    }

    vector<int> ans;
    for(int i = 0; i < resolved; i++) {
        ans.push_back(v[0][i]);
    }
    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for(auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
}
