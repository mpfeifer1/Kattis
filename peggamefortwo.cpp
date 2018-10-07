#include <bits/stdc++.h>
using namespace std;

vector<int> di = {1, -1, 0,  0, 1,  -1};
vector<int> dj = {0,  0, 1, -1,  1, -1};

map< pair<vector<vector<int>>,bool>, int> memo;

bool bounds(int i, int j) {
    if(i < 0) return false;
    if(j < 0) return false;
    if(i >= 5) return false;
    if(j > i) return false;
    return true;
}

int getScore(vector<vector<int>>& board, bool maxPlayer = true) {
    if(memo.count({board,maxPlayer}) > 0) {
        return memo[{board,maxPlayer}];
    }

    int bestScore = 1e9;
    if(maxPlayer) bestScore = -1e9;
    int temp;
    bool jumpFound = false;
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j <= i; ++j) {
            if(board[i][j] == 0) continue;
            for(int k = 0; k < 6; ++k) {
                int nexti = i+2*di[k];
                int nextj = j+2*dj[k];
                if(!bounds(nexti, nextj)) continue;
                if(board[i+di[k]][j+dj[k]] == 0) continue;
                if(board[nexti][nextj] != 0) continue;
                jumpFound = true;
                board[nexti][nextj] = board[i][j];
                board[i][j] = 0;
                temp = board[i+di[k]][j+dj[k]];
                board[i+di[k]][j+dj[k]] = 0;
                if(maxPlayer) {
                    bestScore = max(bestScore, temp*board[nexti][nextj] + getScore(board, !maxPlayer));
                } else {
                    bestScore = min(bestScore, -temp*board[nexti][nextj] + getScore(board, !maxPlayer));
                }
                board[i][j] = board[nexti][nextj];
                board[nexti][nextj] = 0;
                board[i+di[k]][j+dj[k]] = temp;
            }
        }
    }

    if(!jumpFound) {
        return 0;
    }

    memo[{board,maxPlayer}] = bestScore;
    return bestScore;
}

int main() {
    vector<vector<int> > arr(5);
    for(int i = 0; i < 5; ++i) {
        arr[i].resize(i+1);
        for(int j = 0; j <= i; ++j) {
            cin >> arr[i][j];
        }
    }
    cout << getScore(arr) << '\n';
    return 0;
}



























