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





vector<string> split(string s) {
    vector<string> ret = {""};
    for(auto i : s) {
        if(i == ' ') continue;
        else if(i == 'v') ret.pb("");
        else ret.back().pb(i);
    }
    return ret;
}

string getbits(int bits, int n) {
    string res;
    for(int i = 0; i < bits; i++) {
        res.pb((n%2)+'0');
        n /= 2;
    }
    reverse(all(res));
    return res;
}

bool solve() {
    int n, m;
    cin >> n >> m;
    cin.ignore();

    // loop through all rules, if there's an impossible one, quit
    vector<vector<int>> rules;
    for(int i = 0; i < m; i++) {
        string s;
        getline(cin, s);
        vector<int> here(21,0);

        vector<string> bits = split(s);

        bool alwaystrue = false;

        for(auto i : bits) {
            int val = 1;
            if(i[0] == '~') {
                val = -1;
                i.erase(0,1);
            }
            i.erase(0,1);
            int idx = stoi(i)-1;

            if(here[idx] * val == -1) {
                alwaystrue = true;
            }
            here[idx] = val;
        }

        if(!alwaystrue) {
            rules.pb(here);
        }
    }

    /*
    for(auto i : rules) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
    */

    bool works = false;
    for(int i = 0; i < 1<<n; i++) {
        //cout << getbits(n, i) << " ";
        bool worksoverall = true;
        for(auto j : rules) {
            bool workshere = false;
            for(int k = 0; k < n; k++) {
                if((i&(1<<k)) >= 1 && j[k] == 1) {
                    workshere = true;
                }
                if((i&(1<<k)) == 0 && j[k] == -1) {
                    workshere = true;
                }
            }
            if(!workshere) {
                worksoverall = false;
                break;
            }
        }
        //cout << worksoverall << endl;
        if(worksoverall) {
            works = true;
            break;
        }
    }

    return works;
}

int main() {
    //file();
    fast();

    int cases;
    cin >> cases;
    while(cases--) {
        if(solve()) {
            cout << "satisfiable" << endl;
        }
        else {
            cout << "unsatisfiable" << endl;
        }
    }

    return 0;
}
