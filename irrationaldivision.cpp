#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
const int inf2 = 1e8;

int memo[102][102][2][2];

int solve(int row, int col, bool ULblack, bool myTurn) {
    if(row == 0 || col == 0) return 0;
    int &dp = memo[row][col][ULblack][myTurn];
    if(dp != inf) return dp;
    if(myTurn) dp = -inf2;
    else dp = inf2;
    if(myTurn) {
        for(int rows = 1; rows <= row; ++rows) {
            int val;
            if((rows*col)%2 == 0) {
                val = 0;
            } else {
                if(ULblack) val = 1;
                else val = -1;
            }
            int newULblack = ULblack;
            if(rows%2 == 1) newULblack = !newULblack;
            dp = max(dp, val + solve(row-rows, col, newULblack, !myTurn));
        }
    } else {
        for(int cols = 1; cols <= col; ++cols) {
            int val;
            if((row*cols)%2 == 0) {
                val = 0;
            } else {
                bool BLblack = ULblack;
                if(row%2 == 0) BLblack = !BLblack;
                if(BLblack) val = 1;
                else val = -1;
            }
            dp = min(dp, -val + solve(row, col-cols, ULblack, !myTurn));
        }
    }
    return dp;
}

int main() {
    int row, col;
    cin >> row >> col;
    swap(row, col);
    for(int i = 0; i <= row; ++i) {
        for(int j = 0; j <= col; ++j) {
            memo[i][j][0][0] = inf;
            memo[i][j][0][1] = inf;
            memo[i][j][1][0] = inf;
            memo[i][j][1][1] = inf;
        }
    }
    cout << solve(row, col, true, true) << '\n';
}
