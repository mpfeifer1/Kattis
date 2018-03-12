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
    fast();

    string s;
    cin >> s;

    string bin;
    for(auto i : s) {
        if(i == '0') {
            bin += "000";
        }
        if(i == '1') {
            bin += "001";
        }
        if(i == '2') {
            bin += "010";
        }
        if(i == '3') {
            bin += "011";
        }
        if(i == '4') {
            bin += "100";
        }
        if(i == '5') {
            bin += "101";
        }
        if(i == '6') {
            bin += "110";
        }
        if(i == '7') {
            bin += "111";
        }
    }

    reverse(all(bin));
    while(bin.size() % 4 != 0) {
        bin.pb('0');
    }
    reverse(all(bin));

    string ans;
    for(int i = 0; i < bin.size(); i += 4) {
        string here = bin.substr(i, 4);
        if(here == "0000") {
            ans.pb('0');
        }
        if(here == "0001") {
            ans.pb('1');
        }
        if(here == "0010") {
            ans.pb('2');
        }
        if(here == "0011") {
            ans.pb('3');
        }
        if(here == "0100") {
            ans.pb('4');
        }
        if(here == "0101") {
            ans.pb('5');
        }
        if(here == "0110") {
            ans.pb('6');
        }
        if(here == "0111") {
            ans.pb('7');
        }
        if(here == "1000") {
            ans.pb('8');
        }
        if(here == "1001") {
            ans.pb('9');
        }
        if(here == "1010") {
            ans.pb('A');
        }
        if(here == "1011") {
            ans.pb('B');
        }
        if(here == "1100") {
            ans.pb('C');
        }
        if(here == "1101") {
            ans.pb('D');
        }
        if(here == "1110") {
            ans.pb('E');
        }
        if(here == "1111") {
            ans.pb('F');
        }
    }

    reverse(all(ans));
    while(ans.back() == '0') {
        ans.pop_back();
    }
    reverse(all(ans));

    if(ans.size() == 0) {
        ans.pb('0');
    }

    cout << ans << endl;

    return 0;
}
