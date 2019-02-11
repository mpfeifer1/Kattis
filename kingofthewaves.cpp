#include <bits/stdc++.h>

using namespace std;

vector<bool> vis;
vector<int> order;
vector<vector<char>> v;

int n;

void dfs(int curr) {
    if(vis[curr]) return;
    vis[curr] = true;
    order.push_back(curr);
    for(int i = 0; i < n; i++) {
        if(v[curr][i] == '1') {
            dfs(i);
        }
    }

}

int main() {
    cin >> n;
    v.resize(n,vector<char>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    vis.resize(n,false);
    dfs(0);

    for(auto i : vis) {
        if(!i) {
            cout << "impossible" << endl;
            return 0;
        }
    }

    for(int i = n-1; i >= 0; i--) {
        cout << order[i] << " ";
    }
    cout << endl;
}
