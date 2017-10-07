#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct edge {
    int n1;
    int n2;
    int w;
};

bool cmp(edge lhs, edge rhs) {
    return lhs.w < rhs.w;
}

bool cmp2(edge lhs, edge rhs) {
    if(lhs.n1 == rhs.n1) {
        return lhs.n2 < rhs.n2;
    }
    return lhs.n1 < rhs.n1;
}

int find(vector<int>& disjoint, int n) {
    if(disjoint[n] == -1) {
        return n;
    }

    int tmp = find(disjoint, disjoint[n]);
    disjoint[n] = tmp;
    return tmp;
}

void join(vector<int>& disjoint, int n1, int n2) {
    n1 = find(disjoint, n1);
    n2 = find(disjoint, n2);

    disjoint[n1] = n2;
}

int main() {
    int n, m;
    while(cin >> n && cin >> m && n != 0) {
        // Read in edges
        vector<edge> v;
        for(int i = 0; i < m; i++) {
            // Read in
            edge e;
            cin >> e.n1 >> e.n2 >> e.w;

            // Make sure edges in correct format
            if(e.n1 > e.n2) {
                swap(e.n1, e.n2);
            }

            // Add
            v.push_back(e);
        }

        // Sort edges by weight
        sort(v.begin(), v.end(), cmp);

        // Set up used node array
        vector<int> disjoint;
        disjoint.resize(n, -1);

        // Set up array of edges to keep and total weight
        vector<edge> keep;
        int weight = 0;

        // Try to add each edge
        for(auto i : v) {
            // If they have the same parent, don't allow a cycle
            int p1 = find(disjoint, i.n1);
            int p2 = find(disjoint, i.n2);
            if(p1 == p2) {
                continue;
            }

            // Otherwise, add
            join(disjoint, i.n1, i.n2);
            weight += i.w;
            keep.push_back(i);
        }

        // Make sure spanning tree is connected
        int trees = 0;
        for(auto i : disjoint) {
            if(i < 0) {
                trees++;
            }
        }
        if(trees > 1) {
            cout << "Impossible" << endl;
            continue;
        }

        // Print total weight
        cout << weight << endl;

        // Print all of the edges
        sort(keep.begin(), keep.end(), cmp2);
        for(auto i : keep) {
            cout << i.n1 << " " << i.n2 << endl;
        }
    }
}
