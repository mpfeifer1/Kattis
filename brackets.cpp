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





int main() {
    //file();
    //fast();

    string s;
    cin >> s;

    vector<int> opening(s.size()+2, 0);
    vector<int> closing(s.size()+2, 0);

    bool openingworks = true;
    int openingcnt = 0;
    for(int i = 1; i <= s.size(); i++) {
        if(s[i-1] == ')') {
            openingcnt--;
        }
        if(s[i-1] == '(') {
            openingcnt++;
        }

        if(openingcnt < 0) {
            openingworks = false;
        }

        if(openingworks) {
            opening[i] = openingcnt;
        }
        else {
            opening[i] = -iinf;
        }
    }

    bool closingworks = true;
    int closingcnt = 0;
    for(int i = s.size(); i > 0; i--) {
        if(s[i-1] == ')') {
            closingcnt++;
        }
        if(s[i-1] == '(') {
            closingcnt--;
        }

        if(closingcnt < 0) {
            closingworks = false;
        }

        if(closingworks) {
            closing[i] = closingcnt;
        }
        else {
            closing[i] = -iinf;
        }
    }

    bool works = false;
    // Swapping range i to j inclusive
    for(int i = 1; i <= s.size(); i++) {
        int open = opening[i-1];
        for(int j = i; j <= s.size(); j++) {

            if(s[j-1] == ')') {
                open++;
            }
            if(s[j-1] == '(') {
                open--;
            }

            if(open < 0) {
                break;
            }

            if(closing[j+1] < 0) {
                continue;
            }

            if(open == closing[j+1]) {
                works = true;
            }
        }
    }

    // Check if sequence is OK to start
    if(openingworks && closingworks) {
        works = true;
    }

    if(works) {
        cout << "possible" << endl;
    }
    else {
        cout << "impossible" << endl;
    }

    return 0;
}
