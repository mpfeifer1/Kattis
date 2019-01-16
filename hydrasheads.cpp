#include <bits/stdc++.h>

using namespace std;
int inf = 1 << 29;

map<pair<int,int>,int> memo;

int solve(int h, int t) {
    if(memo.count({h,t})) {
        return memo[{h,t}];
    }

    int best = inf;

    if(h <= 2 && t <= 2) {
        best = min(best,solve(h,t+1));
    }

    if(t >= 2) {
        best = min(best,solve(h+1,t-2));
    }

    if(h >= 2) {
        best = min(best,solve(h-2,t));
    }

    best++;

    memo[{h,t}] = best;
    return best;
}

int main() {
    memo[{1,0}] = inf;
    memo[{0,0}] = 0;
    memo[{2,0}] = 1;
    memo[{1,2}] = 2;
    memo[{0,4}] = 3;

    int n, m;
    while(true) {
        cin >> n >> m;
        if(n == 0 && m == 0) {
            break;
        }
        int best = solve(n,m);
        if(best == inf) best = -1;
        cout << best << endl;
    }
}
