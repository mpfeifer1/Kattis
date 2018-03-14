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





bool isprime(int n) {
    if(n < 2) {
        return false;
    }
    if(n == 2) {
        return true;
    }
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

bool connect(int i, int j) {
    int diff = 0;
    while(i > 0 && j > 0) {
        if(i%10 != j%10) {
            diff++;
        }
        i /= 10;
        j /= 10;
    }
    return diff == 1;
}

int main() {
    //file();
    //fast();

    set<int> all;
    for(int i = 1000; i <= 9999; i++) {
        if(isprime(i)) {
            all.insert(i);
        }
    }

    map<int, set<int>> adj;
    for(auto i : all) {
        adj[i] = {};
        for(auto j : all) {
            if(connect(i,j)) {
                adj[i].insert(j);
            }
        }
    }

    int cases;
    cin >> cases;
    while(cases--) {
        int n1, n2;
        cin >> n1 >> n2;

        map<int,int> vis;
        vis[n1] = 0;
        queue<int> q;
        q.push(n1);

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            for(auto next : adj[curr]) {
                if(vis.count(next) == 0) {
                    vis[next] = vis[curr] + 1;
                    q.push(next);
                }
            }
        }

        cout << vis[n2] << endl;
    }

    return 0;
}
