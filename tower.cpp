#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll find(unordered_map<ll,ll>& d, ll a) {
    if(d[a] == -1) {
        return a;
    }

    d[a] = find(d, d[a]);
    return d[a];
}

void join(unordered_map<ll,ll>& d, ll a, ll b) {
    a = find(d, a);
    b = find(d, b);

    if(a == b) {
        return;
    }

    d[a] = b;
}

vector<ll> buildcycle(unordered_map<ll,ll>& par, ll start) {
    unordered_set<ll> seen;

    while(seen.count(start) == 0) {
        seen.insert(start);
        start = par[start];
    }

    vector<ll> cycle;
    for(auto i : seen) {
        cycle.push_back(i);
    }

    return cycle;
}

vector<ll> findcycle(unordered_map<ll,vector<ll>>& adj, vector<ll>& nodes) {
    vector<ll> cycle;

    // Check if a node contains itself
    for(auto i : nodes) {
        for(auto j : adj[i]) {
            if(i == j) {
                cycle.push_back(i);
                return cycle;
            }
        }
    }

    // Check if there's a double edge
    for(auto i : nodes) {
        unordered_set<ll> seen;
        for(auto j : adj[i]) {
            if(seen.count(j) > 0) {
                cycle.push_back(i);
                cycle.push_back(j);
                return cycle;
            }
            seen.insert(j);
        }
    }

    // Find actual cycle
    unordered_map<ll,ll> par;
    unordered_set<ll> vis;

    stack<pair<ll,ll>> s;
    s.push({nodes.back(),-1});

    while(!s.empty()) {
        ll curr = s.top().first;
        ll prev = s.top().second;
        s.pop();

        if(vis.count(curr) > 0) {
            continue;
        }
        vis.insert(curr);

        for(auto i : adj[curr]) {
            if(vis.count(i) > 0 && i != prev) {
                par[i] = curr;
                return buildcycle(par, i);
            }
            if(vis.count(i) > 0) {
                continue;
            }
            par[i] = curr;

            s.push({i, curr});
        }
    }

    return cycle;
}

ll solvecycle(unordered_map<ll,vector<ll>>& adj, vector<ll>& nodes) {
    // Get nodes in cycle
    vector<ll> cycle = findcycle(adj, nodes);

    // Set up visited
    unordered_map<ll,bool> vis;
    for(auto i : nodes) {
        vis[i] = false;
    }

    // Add cycle nodes to total
    ll total = 0;
    queue<ll> q;
    for(auto i : cycle) {
        total += i;
        vis[i] = true;
        q.push(i);
    }

    // BFS from each
    while(!q.empty()) {
        ll curr = q.front();
        q.pop();

        for(auto i : adj[curr]) {
            if(!vis[i]) {
                vis[i] = true;
                total += curr;
                q.push(i);
            }
        }
    }

    return total;
}

ll solvenocycle(unordered_map<ll,vector<ll>>& adj, vector<ll>& nodes) {
    unordered_map<ll,bool> vis;
    ll best = 0;
    for(auto i : nodes) {
        vis[i] = false;
        best = max(best, i);
    }

    queue<ll> q;
    q.push(best);
    vis[best] = true;

    ll total = 0;
    while(!q.empty()) {
        ll curr = q.front();
        q.pop();

        for(auto i : adj[curr]) {
            if(!vis[i]) {
                vis[i] = true;
                total += curr;
                q.push(i);
            }
        }
    }

    return total;
}

ll solve(unordered_map<ll,vector<ll>>& adj, vector<ll>& nodes) {
    // Count Edges and Nodes
    ll n = nodes.size();
    ll m = 0;
    for(auto i : nodes) {
        m += adj[i].size();
    }
    m /= 2;

    // Solve if cycle
    if(n == m) {
        return solvecycle(adj, nodes);
    }

    // Solve if no cycle
    else {
        return solvenocycle(adj, nodes);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    unordered_map<ll, vector<ll>> m;
    unordered_map<ll,ll> d;

    // Take in input
    for(ll i = 0; i < n; i++) {
        ll n1, n2;
        cin >> n1 >> n2;

        m[n1].push_back(n2);
        m[n2].push_back(n1);

        if(d.count(n1) == 0) {
            d[n1] = -1;
        }
        if(d.count(n2) == 0) {
            d[n2] = -1;
        }

        join(d, n1, n2);
    }

    // Split up into connected components
    unordered_map<ll, vector<ll>> comps;
    for(auto i : d) {
        comps[find(d, i.first)].push_back(i.first);
    }

    // For each connected component, solve
    ll total = 0;
    for(auto i : comps) {
        total += solve(m, i.second);
    }

    cout << total << endl;
}
