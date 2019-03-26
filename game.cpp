#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int>> edges;
int inf = 100;

vector<int> getlen(int end) {
    vector<int> dist(n,inf);
    dist[end] = 0;

    bool improved = true;
    while(improved) {
        improved = false;
        for(auto i : edges) {
            int cost = 0;
            for(int j = 0; j < n; j++) {
                if(i.second & (1 << j)) {
                    cost = max(cost,dist[j]);
                }
            }
            cost++;

            if(dist[i.first] > cost) {
                improved = true;
                dist[i.first] = cost;
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        for(int j = 0; j < t; j++) {
            string s;
            cin >> s;

            int mask = 0;
            for(auto i : s) {
                mask |= 1 << (i-'a');
            }

            if(mask & (1 << i)) {
                continue;
            }

            edges.push_back({i,mask});
        }
    }

    vector<vector<int>> ans(n,vector<int>(n));

    for(int i = 0; i < n; i++) {
        ans[i] = getlen(i);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(ans[j][i] == inf) ans[j][i] = -1;
            cout << ans[j][i] << " ";
        }
        cout << endl;
    }
}
