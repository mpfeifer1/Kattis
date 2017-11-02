#include <unordered_map>
#include <iostream>

using namespace std;

typedef long long ll;
unordered_map<ll, ll> f;
ll mod = 1000000000;

ll fib(ll n) {
    if(n == 0) {
        return 0;
    }
    if(n == 1 || n == 2) {
        f[n] = 1;
        return f[n];
    }

    if(f.count(n) > 0) {
        return f[n];
    }

    ll k;
    if(n % 2 == 0) {
        k = n / 2;
        f[n] = fib(k) * (fib(k) + 2 * fib(k-1));
        f[n] %= mod;
    }
    else {
        k = (n+1) / 2;
        f[n] = fib(k) * fib(k) + fib(k-1) * fib(k-1);
        f[n] %= mod;
    }

    return f[n];
}

int main() {
    ll n;
    cin >> n;
    while(n--) {
        ll temp;
        cin >> temp;
        cout << temp;
        cin >> temp;
        cout << " " << fib(temp) << endl;
    }
}
