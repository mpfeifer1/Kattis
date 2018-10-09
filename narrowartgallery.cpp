#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = (ll)1 << 60;

struct state {
    ll needed;
    ll spot;
    bool prevl;
    bool prevr;
};

bool operator<(const state& s1, const state& s2) {
    return tie(s1.needed, s1.spot, s1.prevl, s1.prevr) <
           tie(s2.needed, s2.spot, s2.prevl, s2.prevr);
}

bool operator==(const state& s1, const state& s2) {
    return tie(s1.needed, s1.spot, s1.prevl, s1.prevr) ==
           tie(s2.needed, s2.spot, s2.prevl, s2.prevr);
}

map<state, ll> memo;

ll solve(vector<pair<ll,ll>>& v, int n, state s) {
    if(memo.count(s) > 0) {
        return memo[s];
    }

    ll needed = s.needed;
    ll spot = s.spot;
    bool prevl = s.prevl;
    bool prevr = s.prevr;

    if(spot >= n) {
        if(needed <= 0) {
            return 0;
        }
        else {
            return -inf;
        }
    }

    ll lval = v[spot].first;
    ll rval = v[spot].second;

    ll ans = -inf;

    if(needed <= 0) {
        state next = {needed, spot+1, true, true};
        ans = lval + rval + solve(v, n, next);
        memo[s] = ans;
        return ans;
    }

    if(prevl) {
        state next = {needed-1, spot+1, true, false};
        ans = max(ans, lval + solve(v, n, next));
    }

    if(prevr) {
        state next = {needed-1, spot+1, false, true};
        ans = max(ans, rval + solve(v, n, next));
    }

    state next = {needed, spot+1, true, true};
    ans = max(ans, lval + rval + solve(v, n, next));

    memo[s] = ans;
    return ans;
}

void docase(int n, int m) {
    vector<pair<ll,ll>> v(n);
    for(auto& i : v) {
        cin >> i.first >> i.second;
    }

    memo.clear();
    state s = {m, 0, true, true};
    ll ans = solve(v, n, s);
    cout << ans << endl;
}

int main() {
    int n, m;
    while(cin >> n && cin >> m) {
        if(n == 0 && m == 0) {
            break;
        }
        docase(n, m);
    }
}
