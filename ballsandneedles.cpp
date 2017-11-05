#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

struct point2 {
    ll x;
    ll y;

    bool operator == (const point2& p) const {
        return this->x==p.x && this->y==p.y;
    }

    bool operator < (const point2& p) const {
        return 1000*this->x + this->y < 1000*p.x + p.y;
    }
};

struct point3 {
    ll x;
    ll y;
    ll z;

    bool operator == (const point3& p) const {
        return this->x==p.x && this->y==p.y && this->z==p.z;
    }

    bool operator < (const point3& p) const {
        return 1000000*this->x + 1000*this->y + this->z < 1000000*p.x + 1000*p.y + p.z;
    }
};

ll find(vector<ll>& disjoint, ll a) {
    if(disjoint[a] == -1) {
        return a;
    }

    disjoint[a] = find(disjoint, disjoint[a]);
    return disjoint[a];
}

void join(vector<ll>& disjoint, ll a, ll b) {
    a = find(disjoint, a);
    b = find(disjoint, b);

    if(a == b) {
        return;
    }

    disjoint[a] = b;
}

int main() {
    ll n;
    cin >> n;

    map<point2, ll> seen2;
    map<point3, ll> seen3;

    vector<pair<point2, point2>> needle2;
    vector<pair<point3, point3>> needle3;

    int idx2 = 0;
    int idx3 = 0;
    for(ll i = 0; i < n; i++) {
        ll x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

        point2 p = {x1, y1};
        point2 q = {x2, y2};
        point3 r = {x1, y1, z1};
        point3 s = {x2, y2, z2};

        if(seen2.count(p) == 0) {
            seen2[p] = idx2;
            idx2++;
        }
        if(seen2.count(q) == 0) {
            seen2[q] = idx2;
            idx2++;
        }
        if(seen3.count(r) == 0) {
            seen3[r] = idx3;
            idx3++;
        }
        if(seen3.count(s) == 0) {
            seen3[s] = idx3;
            idx3++;
        }

        if(p < q) {
            swap(p, q);
        }

        if(r < s) {
            swap(r, s);
        }

        needle2.push_back({p, q});
        needle3.push_back({r, s});
    }

    bool cycle2 = false;
    bool cycle3 = false;

    vector<ll> disjoint2(idx2, -1);
    vector<ll> disjoint3(idx3, -1);

    sort(needle2.begin(), needle2.end());
    sort(needle3.begin(), needle3.end());

    needle2.resize(distance(needle2.begin(), unique(needle2.begin(), needle2.end())));
    needle3.resize(distance(needle3.begin(), unique(needle3.begin(), needle3.end())));

    for(auto i : needle2) {
        ll l = seen2[i.first];
        ll r = seen2[i.second];
        if(l == r) {
            continue;
        }
        if(find(disjoint2, l) == find(disjoint2, r)) {
            cycle2 = true;
        }
        join(disjoint2, l, r);
    }

    for(auto i : needle3) {
        ll l = seen3[i.first];
        ll r = seen3[i.second];
        if(find(disjoint3, l) == find(disjoint3, r)) {
            cycle3 = true;
        }
        join(disjoint3, l, r);
    }

    if(cycle3) {
        cout << "True closed chains" << endl;
    }
    else {
        cout << "No true closed chains" << endl;
    }

    if(cycle2) {
        cout << "Floor closed chains" << endl;
    }
    else {
        cout << "No floor closed chains" << endl;
    }
}
