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





string tostr(deque<char> d) {
    string s;
    for(auto i : d) {
        s.pb(i);
    }
    return s;
}

void solve(string s) {
    set<deque<char>> big;

    // Get odd length palindromes
    for(int i = 0; i < s.size(); i++) {
        deque<char> d;
        d.pb(s[i]);
        int hi = i+1;
        int lo = i-1;
        while(lo >= 0 && hi < s.size() && s[lo] == s[hi]) {
            d.push_front(s[lo]);
            d.push_back(s[hi]);
            lo--;
            hi++;
        }
        if(d.size() > 1) {
            big.insert(d);
        }
    }

    // Get even length palindromes
    for(int i = 0; i < s.size()-1; i++) {
        if(s[i] != s[i+1]) {
            continue;
        }
        deque<char> d;
        d.pb(s[i]);
        d.pb(s[i+1]);
        int hi = i+2;
        int lo = i-1;
        while(lo >= 0 && hi < s.size() && s[lo] == s[hi]) {
            d.push_front(s[lo]);
            d.push_back(s[hi]);
            lo--;
            hi++;
        }
        if(d.size() > 1) {
            big.insert(d);
        }
    }

    set<deque<char>> ans;
    for(auto i : big) {
        while(ans.count(i) == 0 && i.size() > 1) {
            ans.insert(i);
            i.pop_back();
            i.pop_front();
        }
    }

    for(auto i : ans) {
        cout << tostr(i) << endl;
    }
}

int main() {
    //file();
    //fast();

    string s;
    while(cin >> s) {
        solve(s);
        cout << endl;
    }

    return 0;
}
