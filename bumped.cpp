#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
ll inf = (ll)1 << 55;

struct edge {
    ll w;
    ll dest;
    bool flight;
};

struct node {
    ll dist;
    ll fdist;

    vector<edge> neighbors;
};

int main() {
    int n, m, f, s, t;
    cin >> n >> m >> f >> s >> t;

    // Fill in list of cities
    node empty;
    empty.dist = inf;
    empty.fdist = inf;
    vector<node> nodes(n, empty);

    for(int i = 0; i < m; i++) {
        ll n1, n2, w;
        cin >> n1 >> n2 >> w;

        nodes[n1].neighbors.push_back({w,n2,false});
        nodes[n2].neighbors.push_back({w,n1,false});
    }

    for(int i = 0; i < f; i++) {
        ll n1, n2;
        cin >> n1 >> n2;

        nodes[n1].neighbors.push_back({0,n2,true});
    }

    priority_queue<pair<ll,ll>> q;
    nodes[s].dist = 0;
    q.push({0,s});

    while(!q.empty()) {
        ll curr = q.top().second;
        q.pop();

        for(auto i : nodes[curr].neighbors) {
            // If it's a flight there
            if(i.flight) {
                // Update path using road->flight only
                if(nodes[curr].dist + i.w < nodes[i.dest].fdist) {
                    nodes[i.dest].fdist = nodes[curr].dist + i.w;
                    q.push({0,i.dest});
                }
            }

            // If it's a road there
            else {
                bool add1 = false, add2 = false;

                // Update path using road->road
                if(nodes[curr].dist + i.w < nodes[i.dest].dist) {
                    nodes[i.dest].dist = nodes[curr].dist + i.w;
                    add1 = true;
                }

                // Update path using flight->flight
                if(nodes[curr].fdist + i.w < nodes[i.dest].fdist) {
                    nodes[i.dest].fdist = nodes[curr].fdist + i.w;
                    add2 = true;
                }

                if(add2) {
                    q.push({0,i.dest});
                }
                else if(add1) {
                    q.push({i.w,i.dest});
                }
            }
        }
    }

    cout << min(nodes[t].fdist, nodes[t].dist) << endl;
}
