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





int n, m;

int toint(string s) {
    int ret = 0;
    for(int i = 0; i < s.size(); i++) {
        ret <<= 1;
        if(s[i] == '1') {
            ret++;
        }
    }
    return ret;
}

string tobin(int n) {
    string s;
    while(n > 0) {
        s.pb(n%2 + '0');
        n /= 2;
    }
    while(s.length() < m) {
        s.pb('0');
    }
    reverse(all(s));
    return s;
}

int main() {
    //file();
    //fast();

    cin >> n >> m;

    int big = (1 << m);

    vector<vector<int>> adj(big);

    int curr = big;
    while(curr--) {
        for(int i = 1; i < big; i <<= 1) {
            adj[curr].pb(curr ^ i);
        }
    }

    vector<int> dist(big, iinf);
    queue<int> q;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int t = toint(s);
        dist[t] = 0;
        q.push(t);
    }

    // BFS
    while(!q.empty()) {
        int here = q.front();
        q.pop();

        for(auto next : adj[here]) {
            if(dist[next] == iinf) {
                dist[next] = dist[here] + 1;
                q.push(next);
            }
        }
    }

    int bestdist = 0;
    int bestval = 0;
    for(int i = 0; i < big; i++) {
        if(dist[i] > bestdist) {
            bestdist = dist[i];
            bestval = i;
        }
    }

    cout << tobin(bestval) << endl;

    return 0;
}
