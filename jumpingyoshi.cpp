#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    unordered_map<int,vector<int>> plus;
    unordered_map<int,vector<int>> minus;

    plus.reserve(n);
    minus.reserve(n);

    for(int i = 0; i < n; i++) {
        cin >> v[i];
        int r = i + v[i];
        int l = i - v[i];

        plus[r].push_back(i);
        minus[l].push_back(i);
    }

    queue<int> q;
    vector<bool> vis(n, false);
    q.push(0);

    int best = 0;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        if(vis[curr]) continue;
        vis[curr] = true;
        best = max(best, curr);

        for(auto i : minus[curr+v[curr]]) {
            q.push(i);
        }
        for(auto i : plus[curr-v[curr]]) {
            q.push(i);
        }
    }

    cout << best << endl;
}
