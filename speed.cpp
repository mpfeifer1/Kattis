#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;

ld inf = 10000000;

ld process(vector<pair<ld, ld>> v, ld c) {
    ld total = 0;
    for(auto i : v) {
        total += i.first / (i.second + c);
    }
    return total;
}

int main() {
    ll segments;
    ld t;

    cin >> segments >> t;

    vector<pair<ld, ld>> v;
    vector<ld> bounds;

    ld lo = inf;
    for(int i = 0; i < segments; i++) {
        pair<ld, ld> p;
        cin >> p.first >> p.second;
        v.push_back(p);
        lo = min(lo, p.second);
    }

    lo = -lo;
    ld hi = 1001001;
    ld ans = t + 1;
    ld mid;
    int count = 0;
    while(abs(ans - t) > .00000001 && count < 200) {
        count++;
        mid = (hi + lo) / 2;
        ans = process(v, mid);

        if(ans > t) {
            lo = mid;
        }
        if(ans < t) {
            hi = mid;
        }
    }

    cout.precision(9);
    cout << fixed;
    cout << mid << endl;
}
