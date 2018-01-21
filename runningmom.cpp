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

    int n;
    cin >> n;


    vector<int> degree(10001, 0);
    vector<vector<int>> adj(10001);
    umap<string, int> conv;

    int cities = 0;
    for(int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;

        if(conv.count(s1) == 0) {
            conv[s1] = cities;
            cities++;
        }
        if(conv.count(s2) == 0) {
            conv[s2] = cities;
            cities++;
        }

        int n1 = conv[s1];
        int n2 = conv[s2];

        adj[n2].pb(n1);
        degree[n1]++;
    }

    queue<int> zeroin;
    for(int i = 0; i < cities; i++) {
        if(degree[i] == 0) {
            zeroin.push(i);
        }
    }

    vector<bool> safe(cities, true);
    while(!zeroin.empty()) {
        int curr = zeroin.front();
        zeroin.pop();

        safe[curr] = false;
        for(auto next : adj[curr]) {
            degree[next]--;
            if(degree[next] == 0) {
                zeroin.push(next);
            }
        }
    }

    string s;
    while(cin >> s) {
        int here = conv[s];
        cout << s << " ";
        if(safe[here]) {
            cout << "safe" << endl;
        }
        else {
            cout << "trapped" << endl;
        }
    }
}
