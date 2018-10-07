#include <bits/stdc++.h>

using namespace std;

int main() {
    int p, q, s;
    cin >> p >> q >> s;

    if(p*q/__gcd(p,q) <= s) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }
}
