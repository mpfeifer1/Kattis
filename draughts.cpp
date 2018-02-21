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





int calc(char v[10][10], int x, int y) {
    int score = 0;

    if(x+2 < 10 && y+2 < 10) {
        if(v[x+1][y+1] == 'B') {
            if(v[x+2][y+2] == '.') {
                v[x][y] = '.';
                v[x+1][y+1] = '.';
                v[x+2][y+2] = 'W';
                score = max(score, 1+calc(v,x+2,y+2));
                v[x][y] = 'W';
                v[x+1][y+1] = 'B';
                v[x+2][y+2] = '.';
            }
        }
    }

    if(x-2 >= 0 && y+2 < 10) {
        if(v[x-1][y+1] == 'B') {
            if(v[x-2][y+2] == '.') {
                v[x][y] = '.';
                v[x][y] = '.';
                v[x-1][y+1] = '.';
                v[x-2][y+2] = 'W';
                score = max(score, 1+calc(v,x-2,y+2));
                v[x][y] = 'W';
                v[x-1][y+1] = 'B';
                v[x-2][y+2] = '.';
            }
        }
    }

    if(x+2 < 10 && y-2 >= 0) {
        if(v[x+1][y-1] == 'B') {
            if(v[x+2][y-2] == '.') {
                v[x][y] = '.';
                v[x][y] = '.';
                v[x+1][y-1] = '.';
                v[x+2][y-2] = 'W';
                score = max(score, 1+calc(v,x+2,y-2));
                v[x][y] = 'W';
                v[x+1][y-1] = 'B';
                v[x+2][y-2] = '.';
            }
        }
    }

    if(x-2 >= 0 && y-2 >= 0) {
        if(v[x-1][y-1] == 'B') {
            if(v[x-2][y-2] == '.') {
                v[x][y] = '.';
                v[x][y] = '.';
                v[x-1][y-1] = '.';
                v[x-2][y-2] = 'W';
                score = max(score, 1+calc(v,x-2,y-2));
                v[x][y] = 'W';
                v[x-1][y-1] = 'B';
                v[x-2][y-2] = '.';
            }
        }
    }

    return score;
}

int main() {
    //file();
    fast();

    int cases;
    cin >> cases;

    while(cases--) {
        char v[10][10];

        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                cin >> v[i][j];
                if(v[i][j] == '#') {
                    v[i][j] = '.';
                }
            }
        }

        int best = 0;
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                if(v[i][j] == 'W') {
                    best = max(best, calc(v, i, j));
                }
            }
        }

        cout << best << endl;
    }

    return 0;
}
