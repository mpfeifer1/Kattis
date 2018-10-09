#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> v;
vector<ll> sumr;
vector<ll> suml;

vector<unordered_map<ll,ll>> memo;

ll solve(ll start, ll need) {
    if(start >= v.size()) return 0;

    if(memo[start].count(need) > 0) {
        return memo[start][need];
    }

    // looking for need + suml[start]
    auto it = lower_bound(suml.begin(), suml.end(), need+suml[start]);
    if(it == suml.end()) return 0;
    ll next = (it - suml.begin());
    ll have = suml[next] - suml[start];

    ll ans = 0;

    for(ll i = next; i < v.size(); i++) {
        if((sumr[i] / have) < ans) {
            break;
        }

        ans = max(ans, 1+solve(i, have));
        have += v[i];
    }

    if(next == v.size()) {
        if(have >= need) ans = max(ans,(ll)1);
    }

    memo[start][need] = ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;

    memo.resize(n);
    for(auto& i : memo) {
        i.reserve(3000);
    }

    v.resize(n);
    for(auto& i : v) cin >> i;

    sumr.resize(n);
    sumr[n-1] = 0;
    for(ll i = n-2; i >= 0; i--) {
        sumr[i] = sumr[i+1] + v[i];
    }

    suml.resize(n+1);
    suml[0] = 0;
    for(ll i = 0; i < n; i++) {
        suml[i+1] = suml[i] + v[i];
    }

    cout << solve(0, 1) << endl;
}
