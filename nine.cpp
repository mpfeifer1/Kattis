#include <iostream>

using namespace std;

typedef long long ll;

ll fast(ll base, ll exp, ll mod) {
    ll res = 1;
    while(exp > 0) {
        if(exp & 1 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }

    return res % mod;
}

int main() {
    ll n;
    cin >> n;
    ll mod = 1000000007;

    for(int i = 0; i < n; i++) {
        ll num;
        cin >> num;
        num--;

        ll ans = (8 * fast(9, num, mod)) % mod;
        cout << ans << endl;
    }
}
