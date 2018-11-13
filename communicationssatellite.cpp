#include <bits/stdc++.h>

using namespace std;
typedef long double ld;

struct edge {
    int n1;
    int n2;
    ld w;
};

vector<pair<ld,ld>> coords;
vector<ld> radius;

ld getdist(int a, int b) {
    ld dx = coords[a].first - coords[b].first;
    ld dy = coords[a].second - coords[b].second;
    return sqrt(dx*dx+dy*dy);
}

bool cmp(edge& e1, edge& e2) {
    return e1.w < e2.w;
}

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

int main() {
    int n; cin >> n;

    coords.resize(n);
    radius.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> coords[i].first >> coords[i].second;
        cin >> radius[i];
    }

    vector<edge> v;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            ld dist = getdist(i,j);
            dist -= radius[i];
            dist -= radius[j];
            if(dist < 0) dist = 0;
            v.push_back({i,j,dist});
        }
    }

    sort(v.begin(), v.end(), cmp);

    vector<int> d(n, -1);
    ld ans = 0;
    for(int i = 0; i < v.size(); i++) {
        if(find(d,v[i].n1) != find(d,v[i].n2)) {
            join(d,v[i].n1,v[i].n2);
            ans += v[i].w;
        }
    }

    cout << fixed;
    cout.precision(8);
    cout << ans << endl;
}
