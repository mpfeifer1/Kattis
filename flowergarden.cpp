#include <bits/stdc++.h>

using namespace std;
typedef long double ld;

ld getdist(ld x1, ld y1, ld x2, ld y2) {
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

bool isprime(int n) {
    if(n < 2) {
        return false;
    }
    if(n == 2) {
        return true;
    }
    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    ld maxdist;
    cin >> maxdist;

    int best = 0;
    int curr = 0;
    ld dist = 0;

    int prevx = 0;
    int prevy = 0;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        dist += getdist(prevx, prevy, x, y);
        prevx = x;
        prevy = y;

        if(dist <= maxdist) {
            curr++;
            if(isprime(curr)) {
                best = curr;
            }
        }
    }

    cout << best << endl;
}

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        solve();
    }
}
