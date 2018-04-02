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





typedef vector<vector<char>> state;

bool inrange(int n) {
    return n >= 0 && n < 5;
}

int main() {
    //file();
    //fast();

    // Set up initial board
    state board;
    board = {{'1', '1', '1', '1', '1'},
             {'0', '1', '1', '1', '1'},
             {'0', '0', ' ', '1', '1'},
             {'0', '0', '0', '0', '1'},
             {'0', '0', '0', '0', '0'}};

    // Prepare BFS
    queue<state> q;
    q.push(board);
    map<state, int> memo;
    memo[board] = 0;

    vector<pair<int,int>> movement;
    movement = {{1,2},{-1,2},{1,-2},{-1,-2},
                {2,1},{-2,1},{2,-1},{-2,-1}};

    // Run BFS
    while(!q.empty()) {
        // Get current state
        state s = q.front();
        q.pop();

        // If max length, quit
        if(memo[s] == 10) {
            break;
        }

        // Find empty spot
        int blankx = 0;
        int blanky = 0;
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if(s[i][j] == ' ') {
                    blankx = i;
                    blanky = j;
                }
            }
        }

        // Move all knights into that spot
        state cpy = s;
        for(auto i : movement) {
            int nextx = blankx + i.first;
            int nexty = blanky + i.second;
            if(inrange(nextx) && inrange(nexty)) {
                swap(cpy[blankx][blanky], cpy[nextx][nexty]);
                if(memo.count(cpy) == 0) {
                    memo[cpy] = memo[s] + 1;
                    q.push(cpy);
                }
                swap(cpy[blankx][blanky], cpy[nextx][nexty]);
            }
        }
    }

    // Process queries
    int cases;
    cin >> cases;
    while(cases--) {
        for(int i = 0; i < 5; i++) {
        cin.ignore();
            for(int j = 0; j < 5; j++) {
                board[i][j] = getchar();
            }
        }

        if(memo.count(board) > 0) {
            cout << "Solvable in " << memo[board] << " move(s)." << endl;
        }
        else {
            cout << "Unsolvable in less than 11 move(s)." << endl;
        }
    }


    return 0;
}
