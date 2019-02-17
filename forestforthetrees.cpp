#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x, y;
ll x1, Y1, x2, y2;

bool contains(ll currX, ll currY) {
    if(currX < x1) return false;
    if(currX > x2) return false;
    if(currY < Y1) return false;
    if(currY > y2) return false;
    return true;
}

int main() {
    cin >> x >> y >> x1 >> Y1 >> x2 >> y2;
    ll GCD = __gcd(x, y);
    if(GCD == 1) {
        cout << "Yes\n";
        return 0;
    }
    ll firstX = x/GCD;
    ll firstY = y/GCD;
    if(!contains(firstX, firstY)) {
        cout << "No\n";
        cout << firstX << ' ' << firstY << '\n';
        return 0;
    }
    ll start = 1, end = GCD, mid;
    bool found = false;
    while(start+1 < end) {
        mid = (start+end)/2;
        if(!contains(firstX*mid, firstY*mid)) {
            found = true;
            end = mid;
        } else start = mid;
    }
    if(found) {
        cout << "No\n";
        cout << firstX*end << ' ' << firstY*end << '\n';
    } else {
        cout << "Yes\n";
    }
}
