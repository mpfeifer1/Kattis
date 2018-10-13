#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
ld eps = .00001;

struct point {
    ld x, y, z;
};

struct junk {
    point init;
    ld r;
    ld dx, dy, dz;
};

ld dist(point p1, point p2) {
    ld x = pow(p1.x-p2.x, 2);
    ld y = pow(p1.y-p2.y, 2);
    ld z = pow(p1.z-p2.z, 2);
    return sqrt(x + y + z);
}

point getpoint(junk p, ld t) {
    point ret;
    ret.x = p.init.x + t*p.dx;
    ret.y = p.init.y + t*p.dy;
    ret.z = p.init.z + t*p.dz;
    return ret;
}

ld ternary(junk ship, junk debris) {
    ld lo = 0;
    ld hi = 1000;
    while(hi - lo > eps) {
        //cout << "search: " << lo << " " << hi << endl;
        ld diff = (hi - lo) / 3;

        ld mi_lo = lo + diff;
        point shiplo = getpoint(ship, mi_lo);
        point debrislo = getpoint(debris, mi_lo);
        ld distlo = dist(shiplo, debrislo);

        ld mi_hi = lo +  2 * diff;
        point shiphi = getpoint(ship, mi_hi);
        point debrishi = getpoint(debris, mi_hi);
        ld disthi = dist(shiphi, debrishi);

        if(distlo < disthi) {
            hi = mi_hi;
        }
        else {
            lo = mi_lo;
        }
    }
    return lo;
}

ld binary(junk ship, junk debris, ld t) {
    ld target = ship.r + debris.r;

    ld lo = 0;
    ld hi = t;
    while(hi - lo > eps) {
        ld mi = (hi + lo) / 2;
        point shipmi = getpoint(ship, mi);
        point debrismi = getpoint(debris, mi);
        ld disthere = dist(shipmi, debrismi);
        if(disthere < target) {
            hi = mi;
        }
        else {
            lo = mi;
        }
    }
    return lo;
}

void solve() {
    junk ship;
    junk debris;

    // Read in the ship
    cin >> ship.init.x;
    cin >> ship.init.y;
    cin >> ship.init.z;
    cin >> ship.r >> ship.dx >> ship.dy >> ship.dz;

    // Read in the debris
    cin >> debris.init.x;
    cin >> debris.init.y;
    cin >> debris.init.z;
    cin >> debris.r >> debris.dx >> debris.dy >> debris.dz;

    // Ternary search on point when they're closest together
    ld t = ternary(ship, debris);

    // If they don't touch, print no collision
    point shipend = getpoint(ship, t);
    point debrisend = getpoint(debris, t);
    ld targetdist = ship.r + debris.r;
    if(dist(shipend, debrisend) > targetdist + eps) {
        cout << "No collision" << endl;
        return;
    }

    // Otherwise, binary search on the initial impact, print answer
    ld ans = binary(ship, debris, t);
    cout << fixed << setprecision(3) << ans << endl;
}

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        solve();
    }
}
