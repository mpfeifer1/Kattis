#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n, m;
    cin >> n >> m;

    vector<ll> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    // contains {price, numtopurchase}
    vector<pair<ll,ll>> p(m);
    for(auto& i : p) {
        cin >> i.second >> i.first;
    }

    sort(v.begin(), v.end());
    sort(p.begin(), p.end());

    ll ans = 0;

    while(v.size() > 0) {
        bool broken = false;
        while(true) {
            if(p.size() == 0) {
                broken = true;
                break;
            }
            if(p.back().second == 0) {
                p.pop_back();
            }
            else {
                break;
            }
        }
        if(broken) break;

        ans += v.back() * p.back().first;
        p.back().second--;
        v.pop_back();
    }

    cout << ans << endl;
}
