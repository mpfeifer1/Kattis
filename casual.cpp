#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = (ll)1000000000;

// All pairs are {t,x}
bool works(vector<pair<ll,ll>>& v, ll t, ll sections) {
    ll used = 0;
    ll covered = -inf;

    for(auto i : v) {
        if(t > i.first) return false;
        // If not covered, expand covered, add a section
        if((i.second - i.first) > covered) {
            used++;
            ll xint = (i.first + i.second);
            ll diff =  -t;
            ll next = xint + 2*diff;
            covered = next;
        }
    }

    return used <= sections;
}

bool cmp(pair<ll,ll>& p1, pair<ll,ll>& p2) {
    ll v1 = p1.first + p1.second;
    ll v2 = p2.first + p2.second;
    if(v1 == v2) return p1.second < p2.second;
    return v1 < v2;
}

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<pair<ll,ll>> v(n);
    for(auto& i : v) {
        cin >> i.first >> i.second;
    }

    // Sort points on their left diagonal
    sort(v.begin(), v.end(), cmp);

    ll lo = -inf;
    ll hi = inf;
    ll ans = -inf;
    while(hi - lo > 1) {
        ll mi = (hi + lo) / 2;
        if(works(v, mi, m)) {
            ans = max(ans, mi);
            lo = mi;
        }
        else {
            hi = mi;
        }
    }
    cout << ans << endl;
}

int main() {
    ll cases;
    cin >> cases;

    for(ll i = 1; i <= cases; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
}
