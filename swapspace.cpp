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





bool cmp1(pair<ll,ll>& p1, pair<ll,ll>& p2) {
    if(p1 == p2) {
        return false;
    }
    if(p1.first == p2.first) {
        return p1.second > p2.second;
    }
    return p1.first < p2.first;
}

bool cmp2(pair<ll,ll>& p1, pair<ll,ll>& p2) {
    if(p1 == p2) {
        return false;
    }
    if(p1.second == p2.second) {
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}

void process(vector<pair<ll,ll>>& v, ll& spaceneeded, ll& space) {
    for(auto& i : v) {
        if(space < i.first) {
            spaceneeded += i.first - space;
            space = i.first;
        }

        space -= i.first;
        space += i.second;
    }
}

int main() {
    //file();
    //fast();

    ll n;
    cin >> n;

    vector<pair<ll,ll>> pos(n);
    vector<pair<ll,ll>> zer(n);
    vector<pair<ll,ll>> neg(n);

    for(int i = 0; i < n; i++) {
        pair<int,int> p;
        cin >> p.first >> p.second;
        if(p.second - p.first > 0) {
            pos.pb(p);
        }
        if(p.second - p.first == 0) {
            zer.pb(p);
        }
        if(p.second - p.first < 0) {
            neg.pb(p);
        }
    }

    sort(all(pos), cmp1);
    sort(all(neg), cmp2);

    ll spaceneeded = 0;
    ll space = 0;

    process(pos, spaceneeded, space);
    process(zer, spaceneeded, space);
    process(neg, spaceneeded, space);

    cout << spaceneeded << endl;

    return 0;
}
