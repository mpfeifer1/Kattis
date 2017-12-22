#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;

    ll prev;
    cin >> prev;

    ll money = 100;
    for(int i = 1; i < n; i++) {
        ll curr;
        cin >> curr;

        if(curr > prev) {
            money += min(money/prev, (ll)100000) * (curr - prev);
        }

        prev = curr;
    }

    cout << money << endl;
}
