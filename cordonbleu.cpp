#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// this is one-indexed
// jobs X workers cost matrix
// cost[i][j] is cost of job i done by worker j
// #jobs must be <= #workers
// Default finds min cost; to find max cost set all costs[i][j] to -costs[i][j]
ll HungarianMatch(const vector<vector<ll>>& a) {
    ll n = a.size()-1;
    ll m = a[0].size()-1;
    vector<ll> u(n+1), v(m+1), p(m+1), way(m+1);
    for(ll i = 1; i <= n; ++i) {
        p[0] = i;
        ll j0 = 0;
        vector<ll> minv(m+1, inf);
        vector<char> used(m+1, false);
        do {
            used[j0] = true;
            ll i0 = p[j0], delta = inf, j1;
            for(ll j = 1; j <= m; ++j)
                if(!used[j]) {
                    ll cur = a[i0][j] - u[i0] - v[j];
                    if(cur < minv[j])
                        minv[j] = cur, way[j] = j0;
                    if(minv[j] < delta)
                        delta = minv[j], j1 = j;
                }
            for(ll j = 0; j <= m; ++j)
                if(used[j])
                    u[p[j]] += delta, v[j] -= delta;
                else
                    minv[j] -= delta;
            j0 = j1;
        } while(p[j0] != 0);
        do {
            ll j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while(j0);
    }

    /*
    // For each N, it contains the M it selected
    vector<ll> ans(n+1);
    for(ll j = 1; j <= m ; ++j)
        ans[p[j]] = j;
    */

    return -v[0];
}

ll dist(pair<ll,ll>& p1, pair<ll,ll>& p2) {
    return abs(p1.first-p2.first) +
        abs(p1.second-p2.second);
}

int main(){
    ll n, m;
    cin >> n >> m;

    vector<pair<ll,ll>> bottles(n);
    vector<pair<ll,ll>> couriers(m);
    for(auto& i : bottles) {
        cin >> i.first >> i.second;
    }
    for(auto& i : couriers) {
        cin >> i.first >> i.second;
    }

    pair<ll,ll> restaraunt;
    cin >> restaraunt.first >> restaraunt.second;

    vector<vector<ll>> costs;
    costs.resize(n+1,vector<ll>(n+m));

    // For each bottle
    for(ll i = 0; i < n; i++) {
        // For each courier
        for(ll j = 0; j < n+m-1; j++) {
            ll costhere = 0;
            // Actual courier
            if(j < m) {
                costhere += dist(bottles[i],couriers[j]);
                costhere += dist(bottles[i],restaraunt);
            }
            // Restaurant and back
            else {
                costhere += 2 * dist(bottles[i],restaraunt);
            }
            costs[i+1][j+1] = costhere;
        }
    }

    cout << HungarianMatch(costs) << endl;
}
