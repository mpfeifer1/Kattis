#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll fastpow(ll base, ll exp, ll mod) {
    base %= mod;
    exp %= mod;
    ll res = 1;
    while(exp > 0) {
        if((exp & 1) == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }

    return res % mod;
}

ll lo = 193;
ll hi = 1610612741;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s;
    cin >> s;
    vector<ll> v;
    for(auto i : s) {
        v.push_back(i-'0');
    }

    // pointer left and right
    ll pl = 0;
    ll pr = s.size()-1;

    // hash left and right
    ll hl = 0;
    ll hr = 0;

    ll ans = 0;
    ll len = 0;

    while(pl < pr) {
        // hash from left
        hl += (v[pl] * fastpow(lo,len,hi)) % hi;
        hl %= hi;

        // hash from right
        hr *= lo;
        hr %= hi;
        hr += v[pr];
        hr %= hi;

        len++;

        if(hl == hr) {
            ans += 2;
            hl = 0;
            hr = 0;
            len = 0;
        }

        pl++;
        pr--;
    }

    if(pl == pr || len > 0) {
        ans++;
    }

    cout << ans << endl;
}
