#include <bits/stdc++.h>

using namespace std;

vector<bool> vis;
vector<int> indeg;
vector<int> adj;

int mafia = 0;

void dfs(int curr, bool ismafia) {
    if(vis[curr]) return;
    vis[curr] = true;
    
    if(ismafia) mafia++;
    indeg[adj[curr]]--;
    if(indeg[adj[curr]] == 0 || ismafia) {
        dfs(adj[curr], !ismafia);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    
    vis.resize(n,false);
    indeg.resize(n,0);
    adj.resize(n);
    
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        t--;
        indeg[t]++;
        adj[i] = t;
    }
    
    for(int i = 0; i < n; i++) {
        if(indeg[i] == 0) {
            dfs(i, true);
        }
    }
    
    int unvis = 0;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            unvis++;
        }
    }
    
    cout << mafia + (unvis/2) << endl;
}
