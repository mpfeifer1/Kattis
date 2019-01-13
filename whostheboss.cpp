#include <bits/stdc++.h>

using namespace std;

struct employee {
    int eid;
    int salary;
    int height;
};

bool cmp(employee& e1, employee& e2) {
    if(e1.height == e2.height) {
        return e1.salary > e2.salary;
    }
    return e1.height > e2.height;
}

bool operator<(const employee& e1, const employee& e2) {
    if(e1.salary == e2.salary) {
        return e1.height > e2.height;
    }
    return e1.salary > e2.salary;
}

void dfs(map<int,vector<int>>& adj, map<int,int>& par, map<int,int>& sub, int curr) {
    sub[curr] = 1;
    for(auto next : adj[curr]) {
        par[next] = curr;
        dfs(adj, par, sub, next);
        sub[curr] += sub[next];
    }
}

int main() {
    int m, q;
    cin >> m >> q;

    vector<employee> employees(m);
    for(auto& i : employees) {
        cin >> i.eid;
        cin >> i.salary;
        cin >> i.height;
    }

    sort(employees.begin(), employees.end(), cmp);
    set<employee> lookup;

    vector<pair<int,int>> edges;
    int root;

    for(auto i : employees) {
        lookup.insert(i);
        auto it = lookup.find(i);
        if(it != lookup.begin()) {
            it--;
            employee e = (*it);

            edges.push_back({e.eid,i.eid});
        }
        else {
            root = i.eid;
        }
    }

    map<int,vector<int>> adj;
    for(auto i : edges) {
        adj[i.first].push_back(i.second);
    }

    map<int,int> par;
    map<int,int> sub;

    par[root] = 0;
    dfs(adj, par, sub, root);

    for(int i = 0; i < q; i++) {
        int t; cin >> t;
        cout << par[t] << " " << sub[t]-1 << endl;
    }
}
