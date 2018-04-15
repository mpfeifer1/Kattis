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





int main() {
    //file();
    //fast();

    int n, m;
    ld p;
    cin >> n >> m >> p;
    p /= 100;

    vector<ld> v1(n);
    for(auto& i : v1) {
        cin >> i;
    }

    vector<ld> v2(m);
    for(auto& i : v2) {
        cin >> i;
    }

    set<ld> s;
    for(auto i : v1) {
        for(auto j : v2) {
            s.insert(i/j);
        }
    }

    ld curr = *s.begin();
    s.erase(curr);
    bool works = true;
    for(auto i : s) {
        if(curr + curr*p < i) {
            works = false;
        }
        curr = i;
    }

    if(works) {
        cout << "Ride on!" << endl;
    }
    else {
        cout << "Time to change gears!" << endl;
    }

    return 0;
}
