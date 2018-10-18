#include <bits/stdc++.h>

using namespace std;
typedef long double ld;

ld dist(ld x1, ld y1, ld x2, ld y2) {
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

ld calc(ld x1, ld y1, ld x2, ld y2, ld x3, ld y3, ld x, ld y) {
    ld ans = 0;
    ans += dist(x1, y1, x, y);
    ans += dist(x2, y2, x, y);
    ans += dist(x3, y3, x, y);
    return ans;
}

int main() {
    ld x1, y1;
    ld x2, y2;
    ld x3, y3;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    ld x = (x1+x2+x3) / 3;
    ld y = (y1+y2+y3) / 3;

    ld best = calc(x1, y1, x2, y2, x3, y3, x, y);

    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    ld t = 1000;
    while(t > .00001) {
        bool found = false;
        for(int i = 0; i < 4; i++) {
            ld nextx = x + t * dx[i];
            ld nexty = y + t * dy[i];
            ld val = calc(x1, y1, x2, y2, x3, y3, nextx, nexty);
            if(val < best) {
                found = true;
                best = val;
                x = nextx;
                y = nexty;
            }
        }

        if(!found) {
            t /= 2;
        }
    }

    cout << fixed << setprecision(5);
    cout << x << " " << y << endl;
}
