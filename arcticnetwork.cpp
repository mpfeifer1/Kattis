#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct point {
    int x, y;
};

struct edge {
    int p1, p2;
    double dist;
};

double dist(point p1, point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
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

bool cmp(edge lhs, edge rhs) {
    return lhs.dist < rhs.dist;
}

int main() {
    int cases;
    cin >> cases;

    while(cases--) {
        int sat, out;
        cin >> sat >> out;

        vector<point> v;

        for(int i = 0; i < out; i++) {
            point p;
            cin >> p.x >> p.y;
            v.push_back(p);
        }

        vector<edge> edges;

        for(int i = 0; i < v.size() - 1; i++) {
            for(int j = i + 1; j < v.size(); j++) {
                double d = dist(v[i], v[j]);
                edge e = {i, j, d};
                edges.push_back(e);
            }
        }

        sort(edges.begin(), edges.end(), cmp);

        vector<int> disjoint(out, -1);
        vector<double> kept;
        for(auto i : edges) {
            if(find(disjoint, i.p1) != find(disjoint, i.p2)) {
                join(disjoint, i.p1, i.p2);
                kept.push_back(i.dist);
            }
        }

        for(int i = 1; i < sat; i++) {
            kept.pop_back();
        }

        cout << fixed;
        cout.precision(2);
        cout << kept.back() << endl;
    }
}
