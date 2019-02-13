#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    ll n, m;
    cin >> n >> m;
    n++; m++;

    // The current power of 2 we're moving by
    ll shift = 0;

    // The current answer
    ll total = 0;

    // While we're still in range
    while(true) {
        // There's at most this many extra squares we can reach
        ll addhere = (1 << shift);

        // Subtract out squares we can't reach in the x dir
        ll sub1 = 0;
        if(addhere > n) sub1 = addhere - n;

        // Subtract out squares we can't reach in the y dir
        ll sub2 = 0;
        if(addhere > m) sub2 = addhere - m;

        // If we can't reach any new squares, quit
        if(addhere - sub1 - sub2 <= 0) break;

        // Add the squares we can reach to our answer
        total += addhere - sub1 - sub2;

        // Increase the power of 2
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
