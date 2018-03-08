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





bool solve(vector<ll>& v, ll t) {
    ll target = -1;
    for(auto& i : v) {
        if(i < t) continue;

        if(target == -1) {
            target = i;
        }
        else {
            if(target != i) {
                return false;
            }
            target = -1;
        }
    }
    return target == -1;
}

int main() {
    //file();
    //fast();

    int n;
    cin >> n;

    vector<ll> v1(n), v2(n);
    map<ll,int> m;
    for(auto& i : v1) {
        cin >> i;
        m[i]++;
    }
    for(auto& i : v2) {
        cin >> i;
    }

    ll lo = 0;
    ll hi = 1000000005;

    for(auto i : m) {
        if(i.second == 1) {
            lo = max(lo, i.first);
        }
    }

    while(hi-lo>1) {
        ll mid = (hi+lo)/2;
        bool works = solve(v1, mid) && solve(v2, mid);
        if(works) {
            hi = mid;
        }
        else {
            lo = mid;
        }
    }

    cout << lo << endl;

    return 0;
}


