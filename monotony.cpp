#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int mono[20][20][20];

inline bool isMono(vector<int>& v) {
    if(v.size() <= 1) return true;
    bool works = true;
    for(int i = 1; i < v.size(); i++) {
        if(v[i] > v[i-1]) works = false;
    }
    if(works) return true;
    works = true;
    for(int i = 1; i < v.size(); i++) {
        if(v[i] < v[i-1]) works = false;
    }
    return works;
}

ll dp[20];

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid;
    grid.resize(n,vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for(int r = 0; r < n; r++) {
        for(int i = 0; i < m; i++) {
            for(int j = i+1; j < m; j++) {
                for(int k = j+1; k < m; k++) {
                    if(grid[r][i] < grid[r][j] && grid[r][j] < grid[r][k]) mono[i][j][k] |= (1 << r);
                    if(grid[r][i] > grid[r][j] && grid[r][j] > grid[r][k]) mono[i][j][k] |= (1 << r);
                }
            }
        }
    }
    
    ll ans = 0;
    for(int mask = 1; mask < (1<<n); mask++) {
        vector<bool> colMono(m);
        int ct = 0;
        for(int i = 0; i < m; i++) {
            vector<int> v;
            for(int j = 0; j < n; j++) {
                if(mask & (1 << j)) {
                    v.push_back(grid[j][i]);
                }
            }

            colMono[i] = isMono(v);
            if(colMono[i]) ct++;
        }

        ans += ct;

        for(int i = 0; i < m; i++) {
            dp[i] = 1;
            if(!colMono[i]) continue;
            for(int j = i+1; j < m; j++) {
                if(!colMono[j]) continue;

                dp[j] = 1;

                for(int k = i+1; k < j; k++) {
                    if(!colMono[k]) continue;

                    if((mask & mono[i][k][j]) == mask) {
                        dp[j] += dp[k];
                    }
                }

                ans += dp[j];
            }
        }
    }

    cout << ans << endl;
}
