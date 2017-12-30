#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct planet {
    ll x, y, z, n;
};

struct edge {
    ll n1, n2, w;
};

edge build(planet p1, planet p2) {
    edge e = {p1.n, p2.n,
              min({abs(p1.x - p2.x),
                   abs(p1.y - p2.y),
                   abs(p1.z - p2.z)})};
    return e;
}

bool cmpx(planet lhs, planet rhs) {
    return lhs.x < rhs.x;
}

bool cmpy(planet lhs, planet rhs) {
    return lhs.y < rhs.y;
}

bool cmpz(planet lhs, planet rhs) {
    return lhs.z < rhs.z;
}

bool cmpedge(edge lhs, edge rhs) {
    return lhs.w < rhs.w;
}

ll find(vector<ll>& v, ll a) {
    if(v[a] == -1) {
        return a;
    }

    v[a] = find(v, v[a]);
    return v[a];
}

void join(vector<ll>& v, ll a, ll b) {
    a = find(v, a);
    b = find(v, b);

    if(a == b) {
        return;
    }

    v[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vector<planet> v(n);
    ll p = 0;
    for(auto& i : v) {
        cin >> i.x >> i.y >> i.z;
        i.n = p++;
    }

    vector<edge> edges;

    sort(v.begin(), v.end(), cmpx);
    for(ll i = 1; i < n; i++) {
        edges.push_back(build(v[i-1], v[i]));
    }

    sort(v.begin(), v.end(), cmpy);
    for(ll i = 1; i < n; i++) {
        edges.push_back(build(v[i-1], v[i]));
    }

    sort(v.begin(), v.end(), cmpz);
    for(ll i = 1; i < n; i++) {
        edges.push_back(build(v[i-1], v[i]));
    }

    // min span tree
    vector<ll> d(n, -1);
    sort(edges.begin(), edges.end(), cmpedge);

    ll total = 0;
    for(auto i : edges) {
        if(find(d, i.n1) != find(d, i.n2)) {
            join(d, i.n1, i.n2);
            total += i.w;
        }
    }

    cout << total << endl;
}
