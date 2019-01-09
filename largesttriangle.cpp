#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll dist(pair<ll, ll> a, pair<ll, ll> b) {
    ll dx1 = b.first - a.first;
    ll dy1 = b.second - a.second;
    return 1LL * dx1 * dx1 + 1LL * dy1 * dy1;
}

ll ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
    ll dx1 = b.first - a.first;
    ll dy1 = b.second - a.second;
    ll dx2 = c.first - a.first;
    ll dy2 = c.second - a.second;
    return 1LL * dx1 * dy2 - 1LL * dy1 * dx2;
}

vector<pair<ll, ll>> getPoly(vector<pair<ll, ll> > &poly) {
    ll n = poly.size();
    pair<ll, ll> least = poly[0];
    ll pos = 0;
    for(ll i = 0; i < n; i++) {
        if(poly[i] < least) {
            least = poly[i];
            pos = i;
        }
    }
    swap(poly[0], poly[pos]);
    sort(poly.begin() + 1, poly.end(), [&](const pair<ll, ll> &a, const pair<ll, ll> &b){
        auto x = ccw(poly[0], a, b);
        if(x != 0) return x > 0;
        return dist(poly[0], a) < dist(poly[0], b);
    });
    vector<pair<ll, ll> > hull;
    for(auto &i : poly) {
        while(hull.size() >= 2 && ccw(hull[hull.size()-2], hull.back(), i) <= 0){
            hull.pop_back();
        }
        hull.push_back(i);
    }
    return hull;
}


inline ll getarea(vector<pair<ll,ll>>& hull, ll lo, ll mi, ll hi) {
    ll n = hull.size();
    lo = (lo + n) % n;
    mi = (mi + n) % n;
    hi = (hi + n) % n;

    ll total = 0;
    total += hull[lo].first * hull[mi].second;
    total += hull[mi].first * hull[hi].second;
    total += hull[hi].first * hull[lo].second;

    total -= hull[mi].first * hull[lo].second;
    total -= hull[hi].first * hull[mi].second;
    total -= hull[lo].first * hull[hi].second;

    total = abs(total);
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;

    vector<pair<ll,ll>> points(n);
    for(auto& i : points) {
        cin >> i.first >> i.second;
    }

    vector<pair<ll,ll>> hull = getPoly(points);
    n = hull.size();

    ll keep = 0;

    // For each start point
    for(ll lo = 0; lo < n; lo++) {
        ll mi = lo+1;

        // For each end point
        for(ll k = 0; k < n-2; k++) {
            ll hi = lo + k + 2;

            ll area = getarea(hull, lo, mi, hi);
            while(true) {
                mi++;
                ll newarea = getarea(hull, lo, mi, hi);
                if(newarea <= area || mi >= hi) {
                    break;
                }
                area = newarea;
            }

            mi = max(lo+1, mi-2);
            keep = max(keep, area);
        }
    }

    cout << fixed;
    cout.precision(6);
    cout << keep / 2.0 << endl;

    return 0;
}
