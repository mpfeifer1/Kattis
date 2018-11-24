#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = (ll)1 << 60;

struct edge {
    ll dest = 0;
    ll weight = 0;
    ll color = 0;
};

struct state {
    ll location = 0;
    ll reds = 0;
    ll blues = 0;
};

bool operator<(const state& s1, const state& s2) {
    return tie(s1.location, s1.reds, s1.blues) <
           tie(s2.location, s2.reds, s2.blues);
}

int main() {
    ll n, m, k1, k2;
    cin >> n >> m >> k1 >> k2;

    vector<vector<edge>> adj(n);

    for(ll i = 0; i < m; i++) {
        ll u, v, x, c;
        cin >> u >> v >> x >> c;
        u--; v--;

        edge e1, e2;
        e1.dest = v; e1.weight = x; e1.color = c;
        e2.dest = u; e2.weight = x; e2.color = c;

        adj[u].push_back(e1);
        adj[v].push_back(e2);
    }

    map<state,ll> dist;
    state s;
    for(ll i = 0; i < n; i++) {
        s.location = i;
        for(ll j = 0; j <= k1; j++) {
            s.reds = j;
            for(ll k = 0; k <= k2; k++) {
                s.blues = k;
                dist[s] = inf;
            }
        }
    }

    ll start, end;
    cin >> start >> end;
    start--; end--;

    state startstate;
    startstate.location = start;

    state endstate;
    endstate.location = end;
    endstate.reds = k1;
    endstate.blues = k2;

    priority_queue<pair<ll,state>> q;
    q.push({0,startstate});
    dist[startstate] = 0;

    while(!q.empty()) {
        state curr = q.top().second;
        q.pop();

        // for each edge from here, travel
        ll currnode = curr.location;
        ll reds = curr.reds;
        ll blues = curr.blues;

        if(reds > k1) continue;
        if(blues > k2) continue;

        for(auto i : adj[currnode]) {
            state next;
            next.location = i.dest;
            next.reds = reds;
            next.blues = blues;
            if(i.color == 1) next.reds++;
            if(i.color == 2) next.blues++;

            if(dist[next] > dist[curr] + i.weight) {
                dist[next] = dist[curr] + i.weight;
                q.push({-dist[next],next});
            }
        }
    }

    if(dist[endstate] != inf) {
        cout << dist[endstate] << endl;
    }
    else {
        cout << -1 << endl;
    }
}
