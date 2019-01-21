#include <bits/stdc++.h>

using namespace std;
int inf = 1 << 29;

int memo[1<<15];
bool works[1<<15];

int main() {
    int n, m;
    while(cin >> n && cin >> m) {
        if(n == 0 && m == 0) break;
        for(int i = 0; i < (1<<n); i++) memo[i] = inf;

        unordered_map<string,int> conv;
        vector<vector<bool>> hate(n,vector<bool>(n,false));

        for(int i = 0; i < m; i++) {
            string s1, s2;
            cin >> s1 >> s2;

            if(conv.count(s1) == 0) {
                int t = conv.size();
                conv[s1] = t;
            }
            if(conv.count(s2) == 0) {
                int t = conv.size();
                conv[s2] = t;
            }

            int n1 = conv[s1];
            int n2 = conv[s2];

            hate[n1][n2] = true;
            hate[n2][n1] = true;
        }

        for(int i = 0; i < (1<<n); i++) {
            works[i] = true;

            for(int j = 0; j < n; j++) {
                bool broken = false;
                if(!(i & (1<<j))) continue;
                for(int k = 0; k < n; k++) {
                    if(i & (1<<k)) {
                        if(hate[j][k]) {
                            works[i] = false;
                            broken = true;
                            break;
                        }
                    }
                }
                if(broken) break;
            }
        }

        for(int mask = 1; mask < (1<<n); mask++) {
            if(works[mask]) {
                memo[mask] = 1;
                continue;
            }

            int best = inf;
            for(int sub = mask; sub; sub = (sub-1)&mask) {
                int rest = mask ^ sub;
                if(works[sub]) {
                    best = min(best, 1 + memo[rest]);
                }
            }
            memo[mask] = best;
        }

        cout << memo[(1<<n)-1] << endl;
    }
}
