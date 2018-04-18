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





typedef map<pair<int,int>,char> state;
map<state,int> m;

bool inrange(int w, int h, int currx, int curry) {
    return currx >= 0 && curry >= 0 && currx <= h+1 && curry <= w+1;
}

void printstate(state curr, vector<vector<char>> board, int w, int h) {
    for(int i = 0; i <= h+1; i++) {
        for(int j = 0; j <= w+1; j++) {
            if(curr.count({i,j}) > 0) {
                cout << curr[{i,j}];
            }
            else {
                cout << board[i][j];
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    //file();
    //fast();

    int n, w, h, l;
    cin >> n >> w >> h >> l;

    vector<vector<char>> board;
    board.resize(h+2, vector<char>(w+2, 'W'));

    state init;

    int endx = -1;
    int endy = -1;
    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'X') {
                endx = i;
                endy = j;
                board[i][j] = '.';
            }
            if(board[i][j] != '.' && board[i][j] != 'W') {
                init[{i,j}] = board[i][j];
                board[i][j] = '.';
            }
        }
    }

    m[init] = 0;
    queue<state> q;
    q.push(init);
    bool printed = false;

    while(!q.empty()) {
        state curr = q.front();
        q.pop();

        // Debugging
        //printstate(curr, board, w, h);

        // If answer, print, quit
        if(curr.count({endx,endy}) > 0 && curr[{endx,endy}] == '1') {
            printed = true;
            cout << m[curr] << endl;
            break;
        }

        // If taken too long, quit
        if(m[curr] >= l) {
            continue;
        }

        // Try moving to all spots
        vector<pair<int,int>> movement = {{1,0},{-1,0},{0,1},{0,-1}};
        for(auto& i : curr) {
            for(auto& j : movement) {
                state next = curr;
                int currchar = i.second;
                next.erase(i.first);

                pair<int,int> spot = i.first;
                for(int k = 0; k < 12; k++) {
                    int currx = spot.first+j.first*k;
                    int curry = spot.second+j.second*k;
                    if(!inrange(w, h, currx, curry)) {
                        break;
                    }
                    if(board[currx][curry] != '.' || next.count({currx,curry}) > 0) {
                        int prevx = spot.first + j.first*(k-1);
                        int prevy = spot.second + j.second*(k-1);
                        next[{prevx,prevy}] = currchar;

                        if(m.count(next) == 0) {
                            m[next] = m[curr] + 1;
                            q.push(next);
                        }
                        break;
                    }
                }
            }
        }
    }

    if(!printed) {
        cout << "NO SOLUTION" << endl;
    }

    return 0;
}
