#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 255, inf = 1e17;

int minDist[N][N];
int len[N];
int S[N], C[N];

int32_t main() {
    int n, m;
    int k, r;
    cin >> n >> m >> k >> r;
    for(int i = 1; i <= n; ++i) {
        cin >> len[i];
    }
    for(int i = 1; i <= n-1; ++i) {
        cin >> S[i] >> C[i];
    }
    for(int i = 0; i <= n; ++i) {//for each seg
        for(int j = 0; j <= m; ++j) {//for each lane
            minDist[i][j] = inf;
        }
    }
    minDist[0][1] = 0;
    for(int i = 1; i <= n; ++i) {//for each seg
        for(int j = 1; j <= m; ++j) {//for each lane
            int maxLaneChanges = len[i]/k;
            for(int k = max(1LL, j-maxLaneChanges); k <= min(m, j+maxLaneChanges); ++k) {
                int laneChanges = abs(k-j);
                int distCurve = 0;
                if(i > 1) {
                    distCurve = S[i-1] + C[i-1]*k;
                }
                minDist[i][j] = min(minDist[i][j], laneChanges*(k+r) + len[i]-laneChanges*k + distCurve + minDist[i-1][k]);
            }
        }
    }
    cout << minDist[n][1] << '\n';
}
