#include <unordered_map>
#include <iostream>
#include <queue>

using namespace std;

int main() {
    int v, e;
    cin >> v >> e;
    while(v != 0 && e != 0) {
        // Map, int, node1, node2
        unordered_map<int, pair<int, int>> edges;
        // Sort all connections by size
        priority_queue<int, vector<int>, greater<int>> lengths;

        // Sor all connections into the data structures
        for(int i = 0; i < e; i++) {
            int n1, n2, dist;
            cin >> n1 >> n2 >> dist;

            edges.insert({dist, {n1, n2}});
            lengths.push(dist);
        }

        // Keep track of all saved connections
        int totalDist = 0;
        int connections = 0;

        // Create a VxV adjacency matrix
        vector<vector<int>> adj;
        adj.resize(v, 0);
        for(int i = 0; i < v; i++) {
            adj[i].resize(v, 0);
        }

        // For each length, add to min spanning tree
        while(!lengths.empty()) {
            // Get Length
            int dist = lengths.top();
            lengths.pop();

            // Edges contains all connections of a given length
            auto edges = lengths.equal_range(dist);

            // For each pair in edges
            for(auto p : edges) {
                // Try the edge
                adj[p->first][p->second] = 1;
                adj[p->second][p->first] = 1;

                // Check for a cycle
                if(!hasCycle(adj)) {
                    // If edge OK, add it, connections++
                    connections++;
                    totalDist += dist;
                }
                else {
                    // Otherwise, remove
                    adj[p->first][p->second] = 0;
                    adj[p->second][p->first] = 0;

                }


            }

            // If there are enough connections,
            if(connections >= v-1) {
                // Print all the data
                // break
            }

            // Temporary
            cout << "Length: " << dist << endl;
        }


        cout << endl << endl;

        cin >> v >> e;
    }
}
