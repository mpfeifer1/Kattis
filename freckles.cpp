#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long double ld;

struct edge {
    int n1;
    int n2;
    ld dist;
};

ld dist(pair<ld, ld> p1, pair<ld, ld> p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

bool cmp(edge lhs, edge rhs) {
    return lhs.dist < rhs.dist;
}

int find(vector<int>& disjoint, int a) {
    if(disjoint[a] == -1) {
        return a;
    }

    disjoint[a] = find(disjoint, disjoint[a]);
    return disjoint[a];
}

void join(vector<int>& disjoint, int a, int b) {
    a = find(disjoint, a);
    b = find(disjoint, b);

    if(a == b) {
        return;
    }

    disjoint[a] = b;
}

int main() {
    int cases;
    cin >> cases;

    bool first = true;
    while(cases--) {
        // Print extra endls
        if(first) {
            first = false;
        }
        else {
            cout << endl;
        }

        // Take in input
        int n;
        cin >> n;
        vector<pair<ld, ld>> v(n);
        for(auto& i : v) {
            cin >> i.first >> i.second;
        }

        // Build edge list
        vector<edge> edges;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                edge e = {i, j, dist(v[i], v[j])};
                edges.push_back(e);
            }
        }

        // Sort edges
        sort(edges.begin(), edges.end(), cmp);

        // Find minimum edges
        ld total = 0;
        vector<int> disjoint(n, -1);

        for(auto& i : edges) {
            if(find(disjoint, i.n1) != find(disjoint, i.n2)) {
                total += i.dist;
                join(disjoint, i.n1, i.n2);
            }
        }

        cout << fixed;
        cout.precision(2);
        cout << total << endl;
    }
}
