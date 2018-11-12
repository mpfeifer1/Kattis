#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll inf = (ll)1 << 60;

struct MinCostMaxFlow {
    vector<vector<ll>> cap, flow, cost;
    vector<ll> dad, pi;
    ll n;

    ll search(ll source, ll sink) {
        vector<bool> found(n+1, false);
        vector<ll> dist(n+1, inf);
        /*
           Arrays.fill(found, false);
           Arrays.fill(dist, inf);
         */
        dist[source] = 0;

        while (source != n) {
            ll best = n;
            found[source] = true;
            for (ll k = 0; k < n; k++) {
                if (found[k]) continue;
                if (flow[k][source] != 0) {
                    ll val = dist[source] + pi[source] - pi[k] - cost[k][source];
                    if (dist[k] > val) {
                        dist[k] = val;
                        dad[k] = source;
                    }
                }
                if (flow[source][k] < cap[source][k]) {
                    ll val = dist[source] + pi[source] - pi[k] + cost[source][k];
                    if (dist[k] > val) {
                        dist[k] = val;
                        dad[k] = source;
                    }
                }
                if (dist[k] < dist[best]) best = k;
            }
            source = best;
        }
        for (ll k = 0; k < n; k++) {
            pi[k] = min(pi[k] + dist[k], inf);
        }

        return found[sink];
    }


    pair<ll,ll> getflow(vector<vector<ll>> param_cap, vector<vector<ll>> param_cost, ll source, ll sink) {
        cap.clear();
        cost.clear();
        flow.clear();
        dad.clear();
        pi.clear();

        n = param_cap.size();

        cap.resize(n, vector<ll>(n));
        cost.resize(n, vector<ll>(n));
        flow.resize(n, vector<ll>(n,0));

        for(ll i = 0; i < n; i++) {
            for(ll j = 0; j < n; j++) {
                cap[i][j] = param_cap[i][j];
                cost[i][j] = param_cost[i][j];
            }
        }

        dad.resize(n,0);
        pi.resize(n,0);

        ll totflow = 0, totcost = 0;
        while(search(source, sink) > 0) {
            ll amt = inf;
            for(ll x = sink; x != source; x = dad[x])
                amt = min(amt, flow[x][dad[x]] != 0 ? flow[x][dad[x]] :
                        cap[dad[x]][x] - flow[dad[x]][x]);
            for(ll x = sink; x != source; x = dad[x]) {
                if(flow[x][dad[x]] != 0) {
                    flow[x][dad[x]] -= amt;
                    totcost -= amt * cost[x][dad[x]];
                }
                else {
                    flow[dad[x]][x] += amt;
                    totcost += amt * cost[dad[x]][x];
                }
            }
            totflow += amt;
        }

        return {totflow, totcost};
    }
};

    // 0 is source
    // 1 is left bank
    // 2 - r+1 are rocks
    // r+2 is right bank
    // r+3 is sink
ll fix(ll n, ll r) {
    if(n == -2) return 1;
    if(n == -1) return r+2;
    return n+2;
}

int main(){
    ll p, r, l;
    cin >> p >> r >> l;

    MinCostMaxFlow flow;

    vector<vector<ll>> cap, cost;
    cap.resize(r+4, vector<ll>(r+4, 0));
    cost.resize(r+4, vector<ll>(r+4, 0));

    // 0 is source
    // 1 is left bank
    // 2 - r+1 are rocks
    // r+2 is right bank
    // r+3 is sink

    cap[0][1] = p;
    cap[r+2][r+3] = p;

    for(int i = 0; i < l; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        n1 = fix(n1,r);
        n2 = fix(n2,r);

        cap[n1][n2] = 1;
        cap[n2][n1] = 1;
        cost[n1][n2] = 1;
        cost[n2][n1] = 1;
    }

    pair<ll,ll> p1 = flow.getflow(cap, cost, 0, r+3);

    if(p1.first < p) {
        cout << p - p1.first << " people left behind" << endl;
    }
    else {
        cout << p1.second << endl;
    }
}
