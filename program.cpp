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
#define umap unordered_map;
#define uset unordered_set;

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





void increase(vector<ll>& f, int idx, ll d) {
    for(int i = idx; i < f.size(); i |= i+1) {
        f[i] += d;
    }
}

ll sum(vector<ll>& f, int idx) {
    ll total = 0;
    for(int i = idx; i > 0; i &= i-1) {
        total += f[i-1];
    }
    return total;
}

ll rangesum(vector<ll>& f, int l, int r) {
    return sum(f, r) - sum(f, l-1);
}

int main() {
    //file();
    fast();

    int n, k;
    cin >> n >> k;
    vector<ll> f(n, 0);

    unordered_map<int,int> m;
    for(int i = 0; i < k; i++) {
        int temp;
        cin >> temp;
        m[temp]++;
    }

    for(auto i : m) {
        int j = 0;
        while(j < n) {
            increase(f, j, i.second);
            j += i.first;
        }
    }

    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;

        cout << rangesum(f,l+1,r+1) << endl;
    }
}
