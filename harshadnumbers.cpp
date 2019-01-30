#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool harshad(ll n) {
    ll c = n;

    ll t = 0;
    while(c > 0) {
        t += c % 10;
        c /= 10;
    }

    return n % t == 0;
}

int main() {
    ll n;
    cin >> n;
    while(!harshad(n)) {
        n++;
    }
    cout << n << endl;
}
