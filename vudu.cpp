#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
ll inf = (ll)1 << 61;

template<class TIn>
using indexed_set = tree<
        TIn, null_type, less<TIn>,
        rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;

    vector<ll> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    ll p;
    cin >> p;
    for(auto& i : v) {
        i -= p;
    }

    // Pair contains {sum, index}
    indexed_set<pair<ll,ll>> s;
    s.insert({0,-1});

    ll sum = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        sum += v[i];
        ans += s.order_of_key({sum, inf});
        s.insert({sum, i});
    }

    cout << ans << endl;
}
