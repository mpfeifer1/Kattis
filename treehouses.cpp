#include <bits/stdc++.h>

using namespace std;

int find(vector<int>& d, int a) {
    if(d[a] == -1) return a;
    return d[a] = find(d, d[a]);
}

void join(vector<int>& d, int a, int b) {
    a = find(d, a);
    b = find(d, b);
    if(a == b) return;
    d[a] = b;
}

double dist(pair<double,double> p1, pair<double,double> p2) {
    double d1 = pow(p1.first - p2.first,2);
    double d2 = pow(p1.second - p2.second,2);
    return sqrt(d1+d2);
}

struct edge {
    int n1, n2;
    double d;
};

bool cmp(edge& e1, edge& e2) {
    return e1.d < e2.d;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    // Read in pairs
    vector<pair<double,double>> v(n);
    for(auto& i : v) {
        cin >> i.first >> i.second;
    }

    // Build disjoint set
    vector<int> d(n, -1);

    // Join the first m together
    for(int i = 1; i < m; i++) {
        d[i] = 0;
    }

    for(int i = 0; i < k; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        join(d, n1-1, n2-1);
    }

    vector<edge> edges;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            edge e;
            e.n1 = i;
            e.n2 = j;
            e.d = dist(v[i], v[j]);
            edges.push_back(e);
        }
    }

    sort(edges.begin(), edges.end(), cmp);

    double total = 0;
    for(auto i : edges) {
        // if not joined, join
        if(find(d,i.n1) != find(d,i.n2)) {
            join(d,i.n1,i.n2);
            total += i.d;
        }
    }

    cout << fixed;
    cout.precision(6);
    cout << total << endl;
}
