// Michael Pfeifer
// Version 04, 2018/02/17

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const ld  pi   = 4.0*atanl(1.0);
const int iinf = 1e9 + 10;
const ll  inf  = 1e18 + 10;
const int mod  = 1000000007;
const ld  prec = .000001;

#define enld endl
#define endl '\n'
#define pb push_back
#define debug(x) cout<<#x<<" -> "<<x<<'\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define umap unordered_map
#define uset unordered_set

template<class TIn>
using indexed_set = tree<
        TIn, null_type, less<TIn>,
        rb_tree_tag, tree_order_statistics_node_update>;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void file() {
    auto a = freopen("a.in",  "r", stdin);
    auto b = freopen("a.out", "w", stdout);
    if(!a || !b) cout << "uh oh" << endl;
}





void nqueens(vector<vector<int>>& board, vector<int>& usedPos, vector<int>& usedNeg, vector<int>& usedRow, int size, int col, int& solution) {
    if(col == size) {
        solution++;
        return;
    }

    for(int row = 0; row < size; row++) {
        if(usedRow[row] == 0 && usedPos[row+col] == 0 && usedNeg[row-col+(size-1)] == 0 && board[row][col] != -1) {
            usedRow[row] = 1;
            usedPos[row+col] = 1;
            usedNeg[row-col+(size-1)] = 1;

            nqueens(board, usedPos, usedNeg, usedRow, size, col+1, solution);

            usedRow[row] = 0;
            usedPos[row+col] = 0;
            usedNeg[row-col+(size-1)] = 0;
        }
    }

    return;
}

int main() {
    //file();
    fast();

    int size, holes;
    while(cin >> size && cin >> holes) {
        if(size == 0 && holes == 0) {
            break;
        }

        int col = 0;
        int solution = 0;

        vector<vector<int>> board;
        vector<int> usedPos, usedNeg, usedRow;

        board.resize(size, vector<int>(size, 0));
        usedPos.resize(size*2-1, 0);
        usedNeg.resize(size*2-1, 0);
        usedRow.resize(size, 0);

        for(int i = 0; i < holes; i++) {
            int xhole, yhole;
            cin >> xhole; cin >> yhole;
            board[xhole][yhole] = -1;
        }

        nqueens(board, usedPos, usedNeg, usedRow, size, col, solution);
        cout << solution << endl;
    }

    return 0;
}
