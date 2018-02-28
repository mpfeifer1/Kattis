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





struct event {
    ld start, end;
};

bool cmp(event& e1, event& e2) {
    if(abs(e1.start - e2.start) < prec) {
        return e1.end > e2.end;
    }
    return e1.start < e2.start;
}

int main() {
    //file();
    fast();

    ld n, l, w;
    while(cin >> n && cin >> l && cin >> w) {
        vector<event> v;
        for(int i = 0; i < n; i++) {
            ld x, r;
            cin >> x >> r;

            if(r <= w/2) {
                continue;
            }

            ld diff = sqrt(pow(r,2) - pow(w/2,2));
            v.pb({max(ld(0),x-diff), min(x+diff, l)});
        }

        /*
        cout << "Right after input" << endl;
        for(auto i : v) {
            cout << i.start << " " << i.end << endl;
        }
        cout << endl << endl;
        */

        sort(all(v), cmp);
        vector<event> actual;
        actual.pb(v[0]);
        for(int i = 1; i < v.size(); i++) {
            if(v[i].end > actual.back().end) {
                actual.pb(v[i]);
            }
        }
        actual.swap(v);

        /*
        cout << "after removing crap" << endl;
        for(auto i : v) {
            cout << i.start << " " << i.end << endl;
        }
        cout << endl << endl;
        */

        ld target = 0;
        ld next = 0;
        int ans = 1;
        bool works = true;
        for(int i = 0; i < v.size(); i++) {
            if(v[i].start <= target) {
                next = max(next, v[i].end);
            }
            else {
                if(abs(target-next) < prec) {
                    works = false;
                    break;
                }
                i--;
                ans++;
                target = next;
            }
        }

        if(next < l) {
            works = false;
        }

        if(works) {
            cout << ans << endl;
        }
        else {
            cout << -1 << endl;
        }
    }

    return 0;
}
