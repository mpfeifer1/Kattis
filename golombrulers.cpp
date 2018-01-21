// Michael Pfeifer
// Version 02, 2018/01/17

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
    //fast();

    string s;
    while(getline(cin, s)) {
        stringstream ss;
        ss << s;

        vector<int> v;
        int n;
        while(ss >> n) {
            v.pb(n);
        }
        sort(all(v));

        vector<bool> good(v.back()+1, false);

        bool notruler = false;
        for(int i = 0; i < v.size(); i++) {
            for(int j = i+1; j < v.size(); j++) {
                if(good[v[j]-v[i]]) {
                    notruler = true;
                }
                good[v[j]-v[i]] = true;
            }
        }

        if(notruler) {
            cout << "not a ruler" << endl;
            continue;
        }

        vector<int> missing;
        for(int i = 1; i <= v.back(); i++) {
            if(!good[i]) {
                missing.pb(i);
            }
        }

        if(missing.size() == 0) {
            cout << "perfect" << endl;
        }
        else {
            cout << "missing ";
            for(auto i : missing) {
                cout << i << " ";
            }
            cout << endl;
        }
    }

}
