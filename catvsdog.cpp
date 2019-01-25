#include <bits/stdc++.h>

using namespace std;

bool match(int curr, vector<vector<int>>& adj, vector<int>& l, vector<int>& r, vector<int>& vis) {
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

int bipartite(vector<vector<int>>& adj, int n, int m) {
    vector<int> l, r, vis;
    l.resize(n, -1);
    r.resize(m, -1);
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

    int ret = 0;
    for(int i = 0; i < n; i++) {
        ret += (l[i] != -1);
    }
    return ret;
}

bool conflict(pair<pair<char,int>,pair<char,int>> p1, pair<pair<char,int>,pair<char,int>> p2) {
    return p1.first == p2.second || p1.second == p2.first;
}

void solve() {
    int c, d, n;
    cin >> c >> d >> n;

    vector<pair<pair<char,int>,pair<char,int>>> catpeople;
    vector<pair<pair<char,int>,pair<char,int>>> dogpeople;

    for(int i = 0; i < n; i++) {
        pair<pair<char,int>,pair<char,int>> person;
        cin >> person.first.first;
        cin >> person.first.second;
        cin >> person.second.first;
        cin >> person.second.second;

        if(person.first.first == 'C') {
            catpeople.push_back(person);
        }
        else {
            dogpeople.push_back(person);
        }
    }

    vector<vector<int>> adj(catpeople.size());
    for(int i = 0; i < catpeople.size(); i++) {
        for(int j = 0; j < dogpeople.size(); j++) {
            if(conflict(catpeople[i], dogpeople[j])) {
                adj[i].push_back(j);
            }
        }
    }

    cout << n - bipartite(adj, catpeople.size(), dogpeople.size()) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int cases;
    cin >> cases;
    while(cases--) {
        solve();
    }
}
