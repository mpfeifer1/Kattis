#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = (ll)1 << 60;

bool match(ll curr, vector<vector<ll>>& adj, vector<ll>& l, vector<ll>& r, vector<ll>& vis) {
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

ll bipartite(vector<vector<ll>>& adj, ll n, ll m) {
    vector<ll> l, r, vis;
    l.resize(n, -1);
    r.resize(m, -1);
    vis.resize(n);

    bool works = true;
    while(works) {
        works = false;
        fill(vis.begin(), vis.end(), 0);
        for(ll i = 0; i < n; i++) {
            if(l[i] == -1) {
                works |= match(i, adj, l, r, vis);
            }
        }
    }

    ll ret = 0;
    for(ll i = 0; i < n; i++) {
        ret += (l[i] != -1);
    }
    return ret;
}

ll dist(pair<ll,ll>& p1, pair<ll,ll>& p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

ll n;
bool works(vector<vector<ll>>& adj, ll k) {
    // remove all edges greater than K, check if we
    // can make a complete matching
    vector<vector<ll>> realadj(n);
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            if(adj[i][j] <= k) {
                realadj[i].push_back(j);
            }
        }
    }

    ll matches = bipartite(realadj, n, n);
    return (matches == n);
}

int main() {
    // idea:
    // binary search on answer
    // remove all edges greater than K
    // then do max bipartite matching
    // if we can match everyone, this works
    // complexity: nsqrt(n) * log2(m)
    // n=100, m=100000000

    cin >> n;

    vector<pair<ll,ll>> tutors(n);
    vector<pair<ll,ll>> students(n);
    for(auto& i : tutors) {
        cin >> i.first >> i.second;
    }
    for(auto& i : students) {
        cin >> i.first >> i.second;
    }

    vector<vector<ll>> adj;
    adj.resize(n, vector<ll>(n, inf));

    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            adj[i][j] = dist(tutors[i], students[j]);
        }
    }

    ll lo = 0;
    ll hi = (ll)1 << 35;
    ll ans = 0;
    while(hi - lo > 0) {
        ll mi = (hi + lo) / 2;
        if(works(adj, mi)) {
            ans = mi;
            hi = ans;
        }
        else {
            lo = mi + 1;
        }
    }

    cout << ans << endl;
}
