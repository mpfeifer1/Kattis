#include <bits/stdc++.h>

using namespace std;

const int Max = 3e5+2;
vector<int> adj[Max], bridgeTree[Max];
bool visited[Max];
int timeIn[Max], currTime = 0, minTime[Max];
vector<pair<int, int> > bridges;

vector<int> p(Max,-1);
int find(vector<int>& p, int x) {return p[x] < 0 ? x : p[x] = find(p,p[x]);}
void merge(vector<int>& p, int x, int y) {
    if((x=find(p,x)) == (y=find(p,y))) return;
    if(p[y] < p[x]) swap(x,y);
    p[x] += p[y];
    p[y] = x;
}

void dfs(int node, int prev) {
    visited[node] = true;
    timeIn[node] = minTime[node] = ++currTime;
    for(int to : adj[node]) {
        if(to != prev) {
            minTime[node] = min(minTime[node], timeIn[to]);
        }
        if(visited[to]) continue;
        dfs(to, node);
        minTime[node] = min(minTime[node], minTime[to]);
        if(minTime[to] > timeIn[node]) {
            bridges.push_back({node, to});
        } else {
            merge(p, node, to);
        }
    }
}

vector<bool> vis;
set<pair<int,int>> skip;
set<pair<int,int>> actuallyskipped;

void dfs2(int curr,vector<bool>& vis) {
    if(vis[curr]) return;
    vis[curr] = true;
    for(auto next : adj[curr]) {
        if(skip.count({curr,next})) {
            actuallyskipped.insert({curr,next});
            continue;
        }
        if(skip.count({next,curr})) {
            actuallyskipped.insert({next,curr});
            continue;
        }
        dfs2(next,vis);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    n++;

    for(int i = 0; i <= n; ++i) {
        minTime[i] = timeIn[i] = Max;
        visited[i] = false;
    }

    int u, v;
    vector<pair<int,int>> edges;
    map<pair<int,int>,int> cntedges;
    for(int i = 0; i < m; ++i) {
        cin >> u >> v;
        u++; v++;
        edges.push_back({u,v});
        cntedges[{min(u,v),max(u,v)}]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    currTime = 0;
    dfs(0,0);

    for(auto i : bridges) {
        if(cntedges[{min(i.first,i.second),max(i.first,i.second)}] == 1) {
            skip.insert(i);
        }
    }

    vis.resize(n,false);
    dfs2(0,vis);

    vector<int> d(n,-1);
    for(auto i : edges) {
        if(actuallyskipped.count(i)) continue;
        if(actuallyskipped.count({i.second,i.first})) continue;
        merge(d,i.first,i.second);
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(find(d,i) != find(d,0)) {
            ans = max(ans,-d[find(d,i)]);
        }
    }

    cout << ans << endl;

    return 0;
}
