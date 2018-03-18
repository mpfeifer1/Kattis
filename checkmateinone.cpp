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





bool inrange(int x, int y) {
    return (x >= 0) && (y >= 0) && (x < 8) && (y < 8);
}

bool checksquare(vector<vector<char>>& v, int x, int y) {
    // Check for kings
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            if(inrange(x+i, y+j)) {
                if(v[x+i][y+j] == 'K') {
                    return false;
                }
            }
        }
    }

    // Check for rooks
    for(int i = x+1; i < 8; i++) {
        if(v[i][y] == 'R') {
            return false;
        }
        if(v[i][y] != '.') {
            break;
        }
    }
    for(int i = x-1; i >= 0; i--) {
        if(v[i][y] == 'R') {
            return false;
        }
        if(v[i][y] != '.') {
            break;
        }
    }
    for(int i = y+1; i < 8; i++) {
        if(v[x][i] == 'R') {
            return false;
        }
        if(v[x][i] != '.') {
            break;
        }
    }
    for(int i = y-1; i >= 0; i--) {
        if(v[x][i] == 'R') {
            return false;
        }
        if(v[x][i] != '.') {
            break;
        }
    }

    return true;
}

bool safe(vector<vector<char>>& v) {
    int x = 0;
    int y = 0;

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(v[i][j] == 'k') {
                x = i;
                y = j;
            }
        }
    }

    bool ok = false;
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            if(inrange(x+i, y+j)) {
                char old = v[x+i][y+j];
                v[x+i][y+j] = '.';
                v[x][y] = '.';

                ok |= checksquare(v, x+i,y+j);

                v[x][y] = 'k';
                v[x+i][y+j] = old;
            }
        }
    }

    return ok;
}

bool check(vector<vector<char>>& v, int x, int y) {
    v[x][y] = '.';

    int newx;
    int newy;

    newx = x;
    newy = y;
    while(true) {
        newx++;
        if(newx >= 8 || v[newx][newy] != '.') {
            break;
        }

        v[newx][newy] = 'R';
        if(!safe(v)) {
            return true;
        }
        v[newx][newy] = '.';
    }

    newx = x;
    newy = y;
    while(true) {
        newx--;
        if(newx < 0 || v[newx][newy] != '.') {
            break;
        }

        v[newx][newy] = 'R';
        if(!safe(v)) {
            return true;
        }
        v[newx][newy] = '.';
    }

    newx = x;
    newy = y;
    while(true) {
        newy++;
        if(newy >= 8 || v[newx][newy] != '.') {
            break;
        }

        v[newx][newy] = 'R';
        if(!safe(v)) {
            return true;
        }
        v[newx][newy] = '.';
    }

    newx = x;
    newy = y;
    while(true) {
        newy--;
        if(newy < 0 || v[newx][newy] != '.') {
            break;
        }

        v[newx][newy] = 'R';
        if(!safe(v)) {
            return true;
        }
        v[newx][newy] = '.';
    }

    v[x][y] = 'R';
    return false;
}

int main() {
    //file();
    fast();

    vector<vector<char>> v;
    v.resize(8, vector<char>(8));

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cin >> v[i][j];
        }
    }

    bool works = false;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(v[i][j] == 'R') {
                works |= check(v, i, j);
            }
        }
    }

    if(works) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}


