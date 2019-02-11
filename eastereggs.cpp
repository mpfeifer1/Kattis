#include <bits/stdc++.h>

using namespace std;
typedef long double ld;

ld getdist(pair<ld,ld> p1, pair<ld,ld> p2) {
    ld d1 = pow(p1.first-p2.first,2);
    ld d2 = pow(p1.second-p2.second,2);
    return sqrt(d1+d2);
}

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

int n, r, b;
vector<vector<ld>> dist;
bool works(ld d) {
    vector<vector<int>> adj(r);
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < b; j++) {
            if(dist[i][j] < d) {
                adj[i].push_back(j);
            }
        }
    }
    return r+b - bipartite(adj,r,b) >= n;
}

int main() {
    cin >> n >> r >> b;

    vector<pair<ld,ld>> reds(r);
    vector<pair<ld,ld>> blues(b);

    for(auto& i : reds) {
        cin >> i.first >> i.second;
    }
    for(auto& i : blues) {
        cin >> i.first >> i.second;
    }

    dist.resize(r, vector<ld>(b));

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < b; j++) {
            dist[i][j] = getdist(reds[i],blues[j]);
        }
    }

    ld lo = 0;
    ld hi = ld(1e19);
    ld eps = .000000001;
    while(hi - lo > eps) {
        ld mi = (hi + lo) / 2;
        if(works(mi)) {
            lo = mi;
        }
        else {
            hi = mi;
        }
    }

    cout << fixed;
    cout.precision(8);
    cout << lo << endl;
}
