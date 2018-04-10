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
        if(i == ' ') {
            ret.pb("");
        }
        else {
            ret.back().pb(i);
        }
    }
    return ret;
}

int main() {
    //file();
    //fast();

    int count = 0;
    double val = 1;

    string s;
    while(getline(cin, s)) {
        vector<string> v = split(s);
        if(v[0] == "buy") {
            int shares = stoi(v[1]);
            int price = stoi(v[2]);
            double newavg = (count * val) + (shares * price);
            newavg /= (count + shares);
            val = newavg;
            count += shares;
        }
        if(v[0] == "sell") {
            int shares = stoi(v[1]);
            int price = stoi(v[2]);
            count -= shares;
        }
        if(v[0] == "split") {
            int split = stoi(v[1]);
            count *= split;
            val /= split;
        }
        if(v[0] == "merge") {
            int split = stoi(v[1]);
            count /= split;
            val *= split;
        }
        if(v[0] == "die") {
            double price = stoi(v[1]);
            cout << fixed;
            cout.precision(3);

            cout << count * (price - (max(price - val,0.0) * .3)) << endl;
        }

    }

    return 0;
}
