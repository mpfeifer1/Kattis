#include <bits/stdc++.h>

using namespace std;

int n, m;

bool match(int curr, vector<set<int>>& adj, vector<int>& l, vector<int>& r, vector<int>& vis) {
    if(vis[curr]) return false;
    vis[curr] = true;

    for(auto next : adj[curr]) {
        if(r[next] == -1 || match(r[next], adj, l, r, vis)) {
            l[curr] = next;
            r[next] = curr;
            return true;
        }
    }
    return false;
}

vector<int> getrow(vector<set<int>>& adj2) {
    vector<set<int>> adj(n);
    for(int i = 0; i < n; i++) {
        for(auto j : adj2[i]) {
            adj[i].insert(j-1);
        }
    }

    vector<int> l, r, vis;
    l.resize(n, -1);
    r.resize(n, -1);
    vis.resize(n);

    bool works = true;
    while(works) {
        works = false;
        fill(vis.begin(), vis.end(), 0);
        for(int i = 0; i < n; i++) {
            if(l[i] == -1) {
                works |= match(i, adj, l, r, vis);
            }
        }
    }

    return l;
}

int main() {
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(n));

    vector<set<int>> rem(n);
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= n; j++) {
            rem[i].insert(j);
        }
    }

    bool works = true;
    for(int i = 0; i < m; i++) {
        set<int> row;
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
            row.insert(v[i][j]);

            if(rem[j].count(v[i][j]) == 0) {
                works = false;
            }
            rem[j].erase(v[i][j]);
        }
        if(row.size() < n) works = false;
    }

    if(!works) {
        cout << "no" << endl;
        return 0;
    }

    for(int i = m; i < n; i++) {
        vector<int> row = getrow(rem);
        for(int j = 0; j < n; j++) {
            v[i][j] = row[j]+1;
            rem[j].erase(v[i][j]);
        }
    }

    cout << "yes" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
