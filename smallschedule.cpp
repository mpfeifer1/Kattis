#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = ((ll)1 << 60) / 1000000;

ll time_long;
ll machines;
ll time_short;
ll num_short;
ll num_long;

bool works(ll time) {
    ll long_used = (time / time_long) * machines;
    if(long_used > num_long) {
        long_used = num_long;
    }

    ll time_left = (machines * time) - (long_used * time_long);
    return long_used == num_long && time_left - (time_short * num_short) >= 0;
}

int main() {
    cin >> time_long >> machines >> num_short >> num_long;
    time_short = 1;

    ll lo = -1;
    ll hi = inf;
    ll ans;

    while(hi - lo >  1) {
        ll mi = (hi + lo) / 2;
        if(works(mi)) {
            hi = mi;
            ans = mi;
        }
        else {
            lo = mi;
        }
    }

    cout << ans << endl;
}
