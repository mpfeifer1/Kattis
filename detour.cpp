#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = (ll)1<<60;

struct edge {
    ll n1, n2, w;
};

int main() {
    ll n, m;
    cin >> n >> m;

    vector<vector<pair<ll,ll>>> adj(n);
    vector<edge> edges;
    for(ll i = 0; i < m; i++) {
        ll n1, n2, w;
        cin >> n1 >> n2 >> w;
        adj[n1].push_back({n2,w});
        adj[n2].push_back({n1,w});
        edges.push_back({n1,n2,w});
    }

    vector<ll> d(n,inf);
    set<pair<ll,ll>> q;
    q.insert({0,1});
    d[1] = 0;

    while(!q.empty()) {
        ll curr = q.begin()->second;
        q.erase(q.begin());

        for(auto i : adj[curr]) {
            ll next = i.first;
            ll weight = i.second;

            if(d[next] > d[curr] + weight) {
                q.erase({d[next],next});
                d[next] = d[curr] + weight;
                q.insert({d[next],next});
            }
        }
    }

    vector<vector<ll>> adj2(n);

    for(auto i : edges) {
        if(d[i.n1] + i.w == d[i.n2]) continue;
        adj2[i.n2].push_back(i.n1);
    }

    for(auto i : edges) {
        if(d[i.n2] + i.w == d[i.n1]) continue;
        adj2[i.n1].push_back(i.n2);
    }

    queue<ll> bq;
    bq.push(0);
    vector<bool> vis(n,false);
    vector<ll> par(n,-1);
    vis[0] = true;

    while(!bq.empty()) {
        ll curr = bq.front();
        bq.pop();

        for(auto next : adj2[curr]) {
            if(!vis[next]) {
                bq.push(next);
                par[next] = curr;
                vis[next] = true;
            }
        }
    }

    if(par[1] == -1) {
        cout << "impossible" << endl;
    }
    else {
        vector<ll> path;
        ll temp = 1;
        while(par[temp] != -1) {
            path.push_back(temp);
            temp = par[temp];
        }
        path.push_back(temp);

        cout << path.size() << " ";
        for(ll i = path.size()-1; i >= 0; i--) {
            cout << path[i] << " ";
        }
        cout << endl;
    }
}
