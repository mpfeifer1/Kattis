#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n, m;
    cin >> n >> m;

    vector<ll> v(n+1);
    for(ll i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for(ll i = 0; i < m; i++) {
        ll t, a, b;
        cin >> t >> a >> b;
        if(t == 1) {
            v[a] = b;
        }
        else {
            cout << abs(v[a]-v[b]) << endl;
        }
    }
}
