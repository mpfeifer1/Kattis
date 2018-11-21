#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = ((ll)1 << 62) + ((ll)1 << 61);

ll calc(ll v1, ll v2) {
    return abs((v1*v1*v1) - (v2*v2*v2));
}

int main() {
    ll n;
    cin >> n;

    vector<pair<ll,ll>> h;
    vector<pair<ll,ll>> a;

    for(ll i = 0; i < n; i++) {
        ll val;
        char c;
        cin >> val >> c;

        if(c == 'h') {
            h.push_back({val,i+1});
        }
        else {
            a.push_back({val,i+1});
        }
    }

    vector<set<ll>> adj(n+1);

    ll m;
    cin >> m;
    for(ll i = 0; i < m; i++) {
        ll n1, n2;
        cin >> n1 >> n2;
        adj[n1].insert(n2);
        adj[n2].insert(n1);
    }

    sort(h.begin(), h.end());
    sort(a.begin(), a.end());

    ll best = inf;

    while(h.size() > 0 && a.size() > 0) {
        ll idx1 = h.back().second;
        ll idx2 = a.back().second;

        ll v1 = h.back().first;
        ll v2 = a.back().first;

        bool greater = v1 > v2;

        // Best here is the absolute difference of the cubes
        ll besthere = calc(v1,v2);

        // If they touch, make them both closer
        // If they touch, we may be able to increment one
        if(adj[idx1].count(idx2)) {
            if(greater) {
                besthere = min(besthere, calc(v1-1, v2+1));
            }
            else {
                besthere = min(besthere, calc(v1+1, v2-1));
            }


            // Tell if we can increment the lower one
            if(greater) {
                for(auto i : adj[idx2]) {
                    if(i == idx1) continue;
                    if(adj[idx1].count(i) == 0) {
                        besthere = min(besthere, calc(v1, v2+1));
                        break;
                    }
                }
            }
            else {
                for(auto i : adj[idx1]) {
                    if(i == idx2) continue;
                    if(adj[idx2].count(i) == 0) {
                        besthere = min(besthere, calc(v1+1, v2));
                        break;
                    }
                }
            }
        }

        // If they don't touch, we can decrement one
        else {
            if(greater) {
                besthere = min(besthere, calc(v1-1, v2));
            }
            else {
                besthere = min(besthere, calc(v1, v2-1));
            }
        }

        best = min(best, besthere);

        if(a.back().first > h.back().first) a.pop_back();
        else h.pop_back();
    }

    cout << best << endl;
}
