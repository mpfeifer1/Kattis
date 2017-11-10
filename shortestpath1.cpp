#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

ll inf = (ll)2 << 55;

struct node {
    vector<pair<ll, ll>> neighbors;
    ll dist;
};

int main() {
    ll n, m, q, s;
    while(cin >> n && cin >> m && cin >> q && cin >> s) {
        if(n == 0 && m == 0 && q == 0 && s == 0) {
            break;
        }

        node temp;
        temp.dist = inf;
        vector<node> nodes(n+1, temp);

        for(ll i = 0; i < m; i++) {
            ll n1, n2, w;
            cin >> n1 >> n2 >> w;

            nodes[n1].neighbors.push_back({n2, w});
        }

        queue<ll> next;
        next.push(s);
        nodes[s].dist = 0;

        while(!next.empty()) {
            ll curr = next.front();
            next.pop();

            for(auto i : nodes[curr].neighbors) {
                ll nextn = i.first;
                ll nextw = i.second;
                if(nodes[curr].dist + nextw < nodes[nextn].dist) {
                    nodes[nextn].dist = nodes[curr].dist + nextw;
                    next.push(nextn);
                }
            }
        }

        for(ll i = 0; i < q; i++) {
            ll query;
            cin >> query;
            ll val = nodes[query].dist;

            if(val >= inf/2) {
                cout << "Impossible" << endl;
            }
            else {
                cout << val << endl;
            }
        }

        cout << endl;
    }
}
