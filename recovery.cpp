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





void print(vector<vector<int>>& grid) {
    for(auto& i : grid) {
        for(auto& j : i) {
            cout << j;
        }
        cout << endl;
    }
}

int main() {
    //file();
    //fast();

    // Grab strings
    string s1, s2;
    cin >> s1 >> s2;

    // Set N and M
    int n = s1.size();
    int m = s2.size();

    // Build actual parities
    vector<int> a1, a2;
    for(auto& i : s1) {
        a1.pb(i-'0');
    }
    for(auto& i : s2) {
        a2.pb(i-'0');
    }

    // Calculate overall parity
    int overall = 0;
    for(auto& i : a1) {
        overall ^= i;
    }
    for(auto& i : a2) {
        overall ^= i;
    }

    // If bad parity, quit
    if(overall == 1) {
        cout << -1 << endl;
        return 0;
    }

    // Current parity in grid
    vector<int> p1, p2;
    p1.resize(n, m%2);
    p2.resize(m, n%2);

    // Build grid
    vector<vector<int>> grid;
    grid.resize(n, vector<int>(m,1));

    // Set first row and col
    for(int i = 1; i < n; i++) {
        grid[i][0] = a1[i] ^ (m%2) ^ 1;
    }
    for(int j = 1; j < m; j++) {
        grid[0][j] = a2[j] ^ (n%2) ^ 1;
    }

    // Set top left corner
    int corner = 0;
    for(int i = 1; i < n; i++) {
        corner ^= grid[i][0];
    }
    grid[0][0] = a2[0] ^ corner;

    // Swap final rectangles
    int i = n-1;
    int j = m-1;
    while(i > 0 && j > 0) {
        while(i > 0 && grid[i][0] != 0) {
            i--;
        }
        while(j > 0 && grid[0][j] != 0) {
            j--;
        }

        if(i > 0 && j > 0) {
            grid[0][0] ^= 1;
            grid[i][0] ^= 1;
            grid[0][j] ^= 1;
            grid[i][j] ^= 1;
        }
    }

    // Print answer
    print(grid);

    return 0;
}
