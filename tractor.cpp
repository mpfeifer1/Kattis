#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    ll n, m;
    cin >> n >> m;
    /*
    if(m > n) {
        swap(n,m);
    }
    */

    n++; m++;

    ll shift = 0;
    ll total = 0;
    while(true) {
        ll addhere = (1 << shift);

        ll sub1 = 0;
        ll sub2 = 0;
        if(addhere > n) sub1 = addhere - n;
        if(addhere > m) sub2 = addhere - m;

        if(addhere - sub1 - sub2 <= 0) break;
        total += addhere - sub1 - sub2;

        shift++;
    }

    cout << total << endl;
}

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        solve();
    }
}
