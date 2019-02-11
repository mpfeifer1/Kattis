#include <bits/stdc++.h>
using namespace std;

int n, m;
int val[20];
bool sumMask[1<<20];
int memo[1<<20];

short solve(int mask) {
    if(memo[mask] != 255) return memo[mask];
    short res = __builtin_popcount(mask)-1;
    int cnt = 0;
    int iterations = (1<<(__builtin_popcount(mask)-1));
    for(int sub = (mask-1)&mask; sub; sub = ((sub-1)&mask)) {
        cnt++;
        if(cnt > iterations) break;
        if(sumMask[sub]) {
            short ans1 = solve(sub);
            if(ans1 >= res) continue;
            ans1 += solve(sub^mask);
            if(res > ans1) res = ans1;
            if(res == 0) break;
        }
    }
    return memo[mask] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    for(int i = 0; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        val[u] -= w;
        val[v] += w;
    }
    for(int i = 0; i < (1<<m); ++i) {
        memo[i] = 255;
        int currSum = 0;
        for(int bit = 0; bit < m; ++bit) {
            if(i&(1<<bit)) {
                currSum += val[bit];
            }
        }
        sumMask[i] = (currSum == 0);
    }
    cout << solve((1<<m)-1) << '\n';
}
