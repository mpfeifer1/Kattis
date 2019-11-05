#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll n, k;
    cin >> n >> k;

    vector<ll> v(n);
    vector<ll> used(n,0);
    for(auto& i : v) {
        cin >> i;
    }

    sort(v.begin(),v.end());

    // {-time,car}
    priority_queue<pair<ll,ll>> q;
    for(ll i = 0; i < min(n,k); i++) {
        q.push({-v[i],i});
    }

    ll rem = n;
    ll ans = 0;
    while(rem > 0) {
        pair<ll,ll> curr = q.top();
        q.pop();
        ans = -curr.first;

        ll car = curr.second;

        if(used[car] == 0) {
            rem -= 5;
        }
        else {
            rem -= 4;
        }

        used[car]++;

        q.push({-v[car] - (used[car] * 2 * v[car]), car});
    }

    cout << ans << endl;
}
