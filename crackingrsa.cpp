#include <iostream>

using namespace std;

typedef long long ll;

ll solve(ll e, ll t) {
    int i = 1;
    while(true) {
        int x = (e * i - 1) % t;
        if(x == 0) {
            return i;
        }
        i++;
    }
}

int main() {
    ll cases;
    cin >> cases;

    while(cases--) {
        ll p, q, e;
        cin >> p >> e;

        for(int i = 2; i <= p; i++) {
            if(p % i == 0) {
                p /= i;
                q = i;
                break;
            }
        }

        ll t = (p-1) * (q-1);

        cout << solve(e, t) << endl;
    }
}
