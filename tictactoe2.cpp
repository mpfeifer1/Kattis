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





set<vector<string>> s;

bool win(vector<string>& v) {
    if(v[0][0] == v[0][1] && v[0][1] == v[0][2] && v[0][0] != '.') {
        return true;
    }
    if(v[1][0] == v[1][1] && v[1][1] == v[1][2] && v[1][0] != '.') {
        return true;
    }
    if(v[2][0] == v[2][1] && v[2][1] == v[2][2] && v[2][0] != '.') {
        return true;
    }

    if(v[0][0] == v[1][0] && v[1][0] == v[2][0] && v[0][0] != '.') {
        return true;
    }
    if(v[0][1] == v[1][1] && v[1][1] == v[2][1] && v[0][1] != '.') {
        return true;
    }
    if(v[0][2] == v[1][2] && v[1][2] == v[2][2] && v[0][2] != '.') {
        return true;
    }

    if(v[0][0] == v[1][1] && v[1][1] == v[2][2] && v[0][0] != '.') {
        return true;
    }
    if(v[0][2] == v[1][1] && v[1][1] == v[2][0] && v[0][2] != '.') {
        return true;
    }

    return false;
}

void process(vector<string>& v, char c) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {

            if(v[i][j] == '.') {
                // Add char
                v[i][j] = c;

                // Add to set
                s.insert(v);

                // If no win, keep going
                if(!win(v)) {
                    if(c == 'X') {
                        process(v, 'O');
                    }
                    else {
                        process(v, 'X');
                    }
                }

                // Remove char
                v[i][j] = '.';
            }

        }
    }
}

int main() {
    //file();
    //fast();

    vector<string> v = {"...","...","..."};
    s.insert(v);

    process(v, 'X');

    int cases;
    cin >> cases;
    while(cases--) {
        vector<string> v(3);
        for(auto& i : v) {
            cin >> i;
        }

        if(s.count(v) > 0) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }

    return 0;
}
