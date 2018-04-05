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





bool isbase(string s, string base) {
    for(auto i : s) {
        bool works = false;
        for(auto j : base) {
            if(i == j) {
                works = true;
                break;
            }
        }
        if(!works) {
            return false;
        }
    }
    return true;
}

ll convert(string s, int base) {
    ll val = 0;
    for(auto i : s) {
        val *= base;
        if(i >= 'A' && i <= 'F') {
            val += i-'A'+10;
        }
        else {
            val += i-'0';
        }
    }
    return val;
}

bool isprime(ll n) {
    if(n < 2) return false;
    if(n == 2) return true;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

void reduce(int& top, int& bot) {
    if(top == 0) {
        bot = 1;
        return;
    }

    int gcd = __gcd(top, bot);
    top /= gcd;
    bot /= gcd;

}

int main() {
    //file();
    //fast();

    int cases;
    cin >> cases;
    while(cases--) {
        int top = 0;
        int bot = 0;

        string s;
        cin >> s;

        if(isbase(s, "01")) {
            bot++;
            if(isprime(convert(s, 2))) {
                top++;
            }
        }

        if(isbase(s, "01234567")) {
            bot++;
            if(isprime(convert(s, 8))) {
                top++;
            }
        }

        if(isbase(s, "0123456789")) {
            bot++;
            if(isprime(convert(s, 10))) {
                top++;
            }
        }

        if(isbase(s, "0123456789ABCDEF")) {
            bot++;
            if(isprime(convert(s, 16))) {
                top++;
            }
        }

        reduce(top, bot);
        cout << top << "/" << bot << endl;
    }

    return 0;
}
