#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = (ll)1<<60;

struct edge {
    ll dest;
    ll weight;
    ll color;
};

struct state {
    ll dist;
    ll subset;
    ll node;
};

bool operator<(const state& s1, const state& s2) {
    if(s1.dist == s2.dist) {
        if(s1.subset == s2.subset) {
            return s1.node < s2.node;
        }
        return s1.subset < s2.subset;
    }
    return s1.dist < s2.dist;
}

ll getbit(char c) {
    if(c == 'R') return 1<<0;
    if(c == 'O') return 1<<1;
    if(c == 'Y') return 1<<2;
    if(c == 'G') return 1<<3;
    if(c == 'B') return 1<<4;
    if(c == 'I') return 1<<5;
    if(c == 'V') return 1<<6;
    return 0;
}

int main() {
    ll n, m;
    cin >> n >> m;

    vector<vector<edge>> adj(n);

    for(ll i = 0; i < m; i++) {
        ll n1, n2, w;
        char c;
        cin >> n1 >> n2 >> w >> c;
        n1--; n2--;

        adj[n1].push_back({n2,w,getbit(c)});
        adj[n2].push_back({n1,w,getbit(c)});
    }

    vector<vector<ll>> dist;
    dist.resize(1<<7, vector<ll>(n, inf));

    set<state> s;
    dist[0][0] = 0;
    s.insert({0,0,0});

    while(!s.empty()) {
        ll subset = s.begin()->subset;
        ll curr = s.begin()->node;
        s.erase(s.begin());

        for(auto i : adj[curr]) {
            ll next = i.dest;
            ll weight = i.weight;
            ll color = i.color;

            ll nextset = subset | color;

            if(dist[nextset][next] > dist[subset][curr] + weight) {
                s.erase({dist[nextset][next], nextset, next});
                dist[nextset][next] = dist[subset][curr] + weight;
                s.insert({dist[nextset][next], nextset, next});
            }
        }
    }

    cout << dist[(1<<7)-1][0] << endl;
}
