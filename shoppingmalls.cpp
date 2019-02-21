#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
ld inf = (ld)100000000000;

struct pos {
    ld x, y, z;
};

ll n, m;

ld getdist(pos& p1, pos& p2) {
    ld d1 = pow(p1.x - p2.x,2);
    ld d2 = pow(p1.y - p2.y,2);
    ld d3 = pow(p1.z - p2.z,2);
    return sqrt(d1+d2+d3);
}

void solve(vector<vector<pair<ll,ld>>>& adj) {
    ll s, t;
    cin >> s >> t;

    vector<ld> dist(n, inf);
    vector<ll> par(n,-1);
    set<pair<ld,ll>> q;
    dist[s] = 0;
    q.insert({0,s});

    while(!q.empty()) {
        ll curr = (*q.begin()).second;
        q.erase(q.begin());

        for(auto i : adj[curr]) {
            ll next = i.first;
            ld weight = i.second;

            if(dist[next] > dist[curr] + weight) {
                q.erase({dist[next],next});
                dist[next] = dist[curr] + weight;
                par[next] = curr;
                q.insert({dist[next],next});
            }
        }
    }

    vector<ll> path;
    ll curr = t;
    while(par[curr] != -1) {
        path.push_back(curr);
        curr = par[curr];
    }
    path.push_back(curr);

    for(ll i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << " ";
    }
    cout << endl;
}

int main() {
    cin >> n >> m;

    vector<pos> v(n);
    for(auto& i : v) {
        cin >> i.z >> i.x >> i.y;
        i.z *= 5;
    }

    vector<vector<pair<ll,ld>>> adj(n);

    for(ll i = 0; i < m; i++) {
        ll n1, n2;
        string s;
        cin >> n1 >> n2 >> s;

        if(s == "walking" || s == "stairs") {
            ld dist = getdist(v[n1],v[n2]);
            adj[n1].push_back({n2,dist});
            adj[n2].push_back({n1,dist});
        }

        if(s == "lift") {
            adj[n1].push_back({n2,1});
            adj[n2].push_back({n1,1});
        }
        if(s == "escalator") {
            ld dist = getdist(v[n1],v[n2]);
            adj[n1].push_back({n2,1});
            adj[n2].push_back({n1,3*dist});
        }
    }

    ll q;
    cin >> q;
    while(q--) {
        solve(adj);
    }
}
