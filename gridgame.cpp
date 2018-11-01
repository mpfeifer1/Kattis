#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool match(int curr, vector<vector<int>>& adj, vector<int>& l, vector<int>& r, vector<int>& vis) {
    if(vis[curr]) return false;
    vis[curr] = true;

    for(auto next : adj[curr]) {
        if(r[next] == -1 || match(r[next], adj, l, r, vis)) {
            l[curr] = next;
            r[next] = curr;
            return true;
        }
    }
    return false;
}

int bipartite(vector<vector<int>>& adj, int n, int m) {
    vector<int> l, r, vis;
    l.resize(n, -1);
    r.resize(m, -1);
    vis.resize(n);

    bool works = true;
    while(works) {
        works = false;
        fill(vis.begin(), vis.end(), 0);
        for(int i = 0; i < n; i++) {
            if(l[i] == -1) {
                works |= match(i, adj, l, r, vis);
            }
        }
    }

    int ret = 0;
    for(int i = 0; i < n; i++) {
        ret += (l[i] != -1);
    }
    return ret;
}

ll n;
vector<vector<ll>> v;

bool works(ll keep) {
    vector<ll> row(n, 0);
    vector<ll> col(n, 0);

    vector<vector<int>> adj(n);

    ll here = 0;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            if(v[i][j] >= keep) {
                adj[i].push_back(j);
            }
        }
    }

    return bipartite(adj, n, n) == n;
}

int main() {
    cin >> n;

    ll hi = 10000000;
    ll lo = 0;

    ll ans = 0;

    v.resize(n, vector<ll>(n));
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    while(hi - lo > 0) {
        ll mi = (hi + lo) / 2;
        if(works(mi)) {
            ans = max(ans, mi);
            lo = mi+1;
        }
        else {
            hi = mi;//-1;
        }
    }

    cout << ans << endl;
}
