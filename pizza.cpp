#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;

ll dist(vector<ll> v, int a, int b) {
    return abs(a-b) * v[b];
}

int main() {
    ll cases;
    cin >> cases;

    for(ll i = 0; i < cases; i++) {
        ll x, y;
        cin >> x >> y;

        // Read in data
        vector<vector<ll>> deliveries;
        deliveries.resize(x, vector<ll>(y, 0));
        for(ll j = 0; j < y; j++) {
            for(ll k = 0; k < x; k++) {
                cin >> deliveries[k][j];
            }
        }

        // Create vals in X and Y directions
        vector<ll> horz;
        vector<ll> vert;
        horz.resize(x, 0);
        vert.resize(y, 0);
        for(ll j = 0; j < x; j++) {
            for(ll k = 0; k < y; k++) {
                horz[k] += deliveries[j][k];
                vert[j] += deliveries[j][k];
            }
        }

        // Pick optimal X direction
        ll bestX = ll(1) << 62;
        for(ull j = 0; j < horz.size(); j++) {
            ll besthere = 0;
            for(ull k = 0; k < horz.size(); k++) {
                besthere += dist(horz, j, k);
            }
            bestX = min(besthere, bestX);
        }

        // Pick optimal Y direction
        ll bestY = ll(1) << 62;
        for(ull j = 0; j < vert.size(); j++) {
            ll besthere = 0;
            for(ull k = 0; k < vert.size(); k++) {
                besthere += dist(vert, j, k);
            }
            bestY = min(besthere, bestY);
        }

        cout << bestX + bestY << " blocks" << endl;
    }
}
