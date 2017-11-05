#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;

ll inf = (ll) 1 << 59;

struct node {
    vector<ll> neighbors;
    ll bestcon;
    ll bestval;
    ll parent;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<node> nodes;
    node start;
    start.bestcon = 0;
    start.bestval = 0;
    start.parent = -1;
    nodes.push_back(start);

    ll n, m;
    cin >> n >> m;

    map<string, ll> to_num;
    to_num["English"] = 0;

    for(ll i = 1; i <= n; i++) {
        string name;
        cin >> name;
        to_num[name] = i;

        node temp;
        temp.bestcon = inf;
        temp.bestval = inf;
        temp.parent = -1;
        nodes.push_back(temp);
    }

    vector<vector<ll>> adj;
    adj.resize(n+1, vector<ll>(n+1, inf));
    for(ll i = 0; i <= n; i++) {
        adj[i][i] = 0;
    }

    for(ll i = 0; i < m; i++) {
        string s1, s2;
        ll dist;
        cin >> s1 >> s2 >> dist;

        nodes[to_num[s1]].neighbors.push_back(to_num[s2]);
        nodes[to_num[s2]].neighbors.push_back(to_num[s1]);
        adj[to_num[s1]][to_num[s2]] = dist;
        adj[to_num[s2]][to_num[s1]] = dist;
    }

    queue<ll> q;
    q.push(0);

    while(!q.empty()) {
        ll curr = q.front();
        q.pop();

        for(auto i : nodes[curr].neighbors) {
            // If we can get to a node with less translations
            if(nodes[curr].bestcon + 1 < nodes[i].bestcon) {
                nodes[i].bestcon = nodes[curr].bestcon + 1;
                nodes[i].bestval = nodes[curr].bestval + adj[curr][i];
                nodes[i].parent = curr;
                q.push(i);
            }

            // If we can get to a node with the same translations and less money
            else if(nodes[curr].bestcon + 1 == nodes[i].bestcon) {
                if(adj[i][curr] <= adj[i][nodes[i].parent]) {
                    nodes[i].bestcon = nodes[curr].bestcon + 1;
                    nodes[i].bestval = nodes[curr].bestval + adj[curr][i];
                    nodes[i].parent = curr;
                    q.push(i);
                }
            }
        }
    }

    ll total = 0;
    for(ll i = 1; i < nodes.size(); i++) {
        node curr = nodes[i];
        if(curr.bestcon > inf/2) {
            cout << "Impossible" << endl;
            return 0;
        }
        total += adj[curr.parent][i];
    }

    cout << total << endl;
}
