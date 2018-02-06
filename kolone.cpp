// Michael Pfeifer
// Version 03, 2018/01/30

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

ll readint(){
    char r;
    bool start=false,neg=false;
    ll ret=0;
    while(true){
        r=getchar();
        if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
            continue;
        }
        if((r-'0'<0 || r-'0'>9) && r!='-' && start){
            break;
        }
        if(start)ret*=10;
        start=true;
        if(r=='-')neg=true;
        else ret+=r-'0';
    }
    if(!neg) return ret;
    else return -ret;
}





int main() {
    //file();
    fast();

    int n, m;
    cin >> n >> m;

    string s1, s2;
    cin >> s1 >> s2;
    reverse(all(s1));

    int shift;
    cin >> shift;

    // Calculate padding
    int pad1 = 50;
    int pad2 = 50 + (n-shift);

    // Add padding
    string p1, p2;
    for(int i = 0; i < pad1; i++) {
        p1 += ' ';
    }
    for(int i = 0; i < pad2; i++) {
        p2 += ' ';
    }
    s1 = p1 + s1;
    s2 = p2 + s2;

    // Debugging
    //cout << s1 << endl << s2 << endl;

    // Go bottom, top, etc...
    string ans;
    for(int i = 0; i < s1.length() || i < s2.length(); i++) {
        if(i < s2.length()) {
            ans.pb(s2[i]);
        }
        if(i < s1.length()) {
            ans.pb(s1[i]);
        }
    }

    // Print ans without padding
    for(auto& i : ans) {
        if(i != ' ') {
            cout << i;
        }
    }
    cout << endl;

    return 0;
}
