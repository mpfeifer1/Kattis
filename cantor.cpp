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





int conv(string s) {
    int val = 0;
    for(int i = 1; i <= 6; i++) {
        val *= 10;
        if(i < s.size()) {
            val += s[i] - '0';
        }
    }
    return val;
}

bool works(int n) {
    set<int> seen;
    while(seen.count(n) == 0) {
        seen.insert(n);
        n *= 3;
        if(n / 1000000 == 1) {
            return false;
        }
        n %= 1000000;
    }
    return true;
}

int main() {
    //file();
    //fast();

    string s;
    while(cin >> s && s != "END") {
        if(s == "0" || s == "1") {
            cout << "MEMBER" << endl;
        }
        else {
            while(s.front() != '.') {
                s.erase(0,1);
            }
            if(works(conv(s))) {
                cout << "MEMBER" << endl;
            }
            else {
                cout << "NON-MEMBER" << endl;
            }
        }
    }

    return 0;
}
