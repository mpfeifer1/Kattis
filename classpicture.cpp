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





bool works(vector<vector<bool>>& d, vector<int> p) {
    for(int i = 1; i < p.size(); i++) {
        if(d[p[i-1]][p[i]]) {
            return false;
        }
    }

    return true;
}

int main() {
    //file();
    //fast();

    int n;
    while(cin >> n) {
        // Read in all names
        vector<string> names(n);
        for(auto& i : names) {
            cin >> i;
        }
        sort(all(names));

        // Build string to int conversion
        umap<string,int> conv;
        for(int i = 0; i < n; i++) {
            conv[names[i]] = i;
        }

        vector<vector<bool>> dislike;
        dislike.resize(n, vector<bool>(n,false));

        // Read in all dislikes
        int m;
        cin >> m;
        for(int i = 0; i < m; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            int n1 = conv[s1];
            int n2 = conv[s2];

            dislike[n1][n2] = true;
            dislike[n2][n1] = true;
        }

        // Build permutation
        vector<int> perm;
        for(int i = 0; i < n; i++) {
            perm.pb(i);
        }

        // Run permutation
        bool printed = false;
        do {
            if(works(dislike, perm)) {
                printed = true;
                for(auto i : perm) {
                    cout << names[i] << " ";
                }
                cout << endl;
                break;
            }
        } while(next_permutation(all(perm)));

        if(!printed) {
            cout << "You all need therapy." << endl;
        }
    }

}
