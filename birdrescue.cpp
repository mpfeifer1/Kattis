#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll manhattan(ll x1, ll y1, ll x2, ll y2) {
    return abs(x1-x2) + abs(y1-y2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n, q;
    cin >> n >> q;

    ll px, py;
    cin >> px >> py;

    vector<ll> dist(2000002, 0);

    for(ll i = 0; i < n; i++) {
        vector<ll> x(2);
        vector<ll> y(2);
        cin >> x[0] >> y[0] >> x[1] >> y[1];
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        if(x[0] <= px && px <= x[1]) {
            x.push_back(px);
        }
        if(y[0] <= py && py <= y[1]) {
            y.push_back(py);
        }

        vector<ll> dists;
        for(auto j : x) {
            for(auto k : y) {
                dists.push_back(manhattan(j, k, px, py));
            }
        }
        sort(dists.begin(), dists.end());

        if(dists.front() <= 2000001) {
            dist[dists.front()]++;
        }
        if(dists.back() <= 2000000) {
            dist[dists.back()+1]--;
        }
    }

    ll sum = 0;
    for(ll i = 0; i < dist.size(); i++) {
        sum += dist[i];
        dist[i] = sum;
    }

    for(ll i = 0; i < q; i++) {
        ll t;
        cin >> t;
        cout << dist[t] << endl;
    }
}
