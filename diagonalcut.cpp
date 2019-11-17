#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll a, b;
    cin >> a >> b;
    ll g = __gcd(a,b);
    a /= g;
    b /= g;
    if(a % 2 == 0 || b % 2 == 0) g = 0;
    cout << g << endl;
}

