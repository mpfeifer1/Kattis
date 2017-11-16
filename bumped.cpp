#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
ll inf = (ll)1 << 55;

// Defind road/flight
struct edge {
    ll w;
    ll dest;
    bool flight;
};

// Define city
struct node {
    ll dist;
    ll fdist;

    vector<edge> neighbors;
};

int main() {
    // Read in input
    int n, m, f, s, t;
    cin >> n >> m >> f >> s >> t;

    // Fill in list of cities
    node empty;
    empty.dist = inf;
    empty.fdist = inf;
    vector<node> nodes(n, empty);

    // Read in roads
    for(int i = 0; i < m; i++) {
        ll n1, n2, w;
        cin >> n1 >> n2 >> w;

        nodes[n1].neighbors.push_back({w,n2,false});
        nodes[n2].neighbors.push_back({w,n1,false});
    }

    // Read in flights
    for(int i = 0; i < f; i++) {
        ll n1, n2;
        cin >> n1 >> n2;

        nodes[n1].neighbors.push_back({0,n2,true});
    }

    // Prepare for Dijkstra's
    priority_queue<pair<ll,ll>> q;
    nodes[s].dist = 0;
    q.push({0,s});

    // Run Dijkstra's
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
                bool add = false;

                // Update path using road->road
                if(nodes[curr].dist + i.w < nodes[i.dest].dist) {
                    nodes[i.dest].dist = nodes[curr].dist + i.w;
                    add = true;
                }

                // Update path using flight->flight
                if(nodes[curr].fdist + i.w < nodes[i.dest].fdist) {
                    nodes[i.dest].fdist = nodes[curr].fdist + i.w;
                    add = true;
                }

                // Add to queue
                if(add) {
                    q.push({i.w,i.dest});
                }
            }
        }
    }

    // Print answer
    cout << min(nodes[t].fdist, nodes[t].dist) << endl;
}
