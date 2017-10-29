#include <algorithm>
#include <set>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

ll inf = (ll)2 << 58;

struct edge {
    ll n1;
    ll n2;
    ll dist;
};

bool cmp(edge lhs, edge rhs) {
    return lhs.dist < rhs.dist;
}

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
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll v;
    cin >> v;

    vector<edge> e;
    for(ll i = 0; i < v; i++) {
        for(ll j = 0; j < v; j++) {
            ll num;
            cin >> num;
            if(i != j) {
                e.push_back({i, j, num});
            }
        }
    }

    sort(e.begin(), e.end(), cmp);

    vector<ll> disjoint(v, -1);

    for(auto i : e) {
        ll n1 = find(disjoint, i.n1);
        ll n2 = find(disjoint, i.n2);
        if(n1 != n2) {
            cout << i.n1 + 1 << " " << i.n2+1 << endl;
            join(disjoint, n1, n2);
        }
    }
}
