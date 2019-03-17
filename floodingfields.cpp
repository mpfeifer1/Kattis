#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll inf = (ll)1 << 60;

struct maxflow {

    struct edge {
        ll a, b, cap, flow;
    };

    ll n, s, t;
    vector<ll> d, ptr, q;
    vector<edge> e;
    vector<vector<ll>> g;

    maxflow(int _n, int _s, int _t) : n(_n), s(_s), t(_t) {
        d.resize(n);
        ptr.resize(n);
        q.resize(n);
        g.resize(n);
    }

    void addedge(ll a, ll b, ll cap) {
        edge e1 = { a, b, cap, 0 };
        edge e2 = { b, a, 0, 0 };
        g[a].push_back((ll) e.size());
        e.push_back(e1);
        g[b].push_back((ll) e.size());
        e.push_back(e2);
    }

    bool bfs() {
        ll qh=0, qt=0;
        q[qt++] = s;
        d.assign(d.size(), -1);
        d[s] = 0;
        while(qh < qt && d[t] == -1) {
            ll v = q[qh++];
            for(size_t i=0; i<g[v].size(); ++i) {
                ll id = g[v][i],
                    to = e[id].b;
                if(d[to] == -1 && e[id].flow < e[id].cap) {
                    q[qt++] = to;
                    d[to] = d[v] + 1;
                }
            }
        }
        return d[t] != -1;
    }

    ll dfs(ll v, ll flow) {
        if(!flow) return 0;
        if(v == t) return flow;
        for(; ptr[v]<(ll)g[v].size(); ++ptr[v]) {
            ll id = g[v][ptr[v]];
            ll to = e[id].b;
            if(d[to] != d[v] + 1)  continue;
            ll pushed = dfs(to, min (flow, e[id].cap - e[id].flow));
            if(pushed) {
                e[id].flow += pushed;
                e[id^1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

    ll getflow() {
        ll flow = 0;
        for(;;) {
            if(!bfs())  break;
            ptr.assign(ptr.size(), 0);
            while(ll pushed = dfs(s,inf)) {
                flow += pushed;
            }
        }
        return flow;
    }

};


int n, k, h;

// TRUE = IN
// FALSE = OUT
inline int get(int r, int c, int t, bool in) {
    return (((r*n+c)*h+t)*2)+in;
}

inline bool inrange(int r, int c) {
    return r < n && c < n && r >= 0 && c >= 0;
}

int main() {
    cin >> n >> k >> h;

    // Read the grid
    vector<vector<int>> grid;
    grid.resize(n,vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Read the cows
    vector<pair<int,int>> cows(k);
    for(auto& i : cows) {
        cin >> i.first >> i.second;
    }

    // Read the water levels
    vector<int> water(h);
    for(auto& i : water) {
        cin >> i;
    }
    water.insert(water.begin(),-1);
    h++;

    // Define the flow graph
    int N = (n*n*h*2) + 2;
    int S = N-1;
    int T = N-2;
    maxflow mf(N,S,T);

    // Source to each cow
    for(auto i : cows) {
        mf.addedge(S,get(i.first,i.second,0,true),1);
    }

    // Each node at the last time to the sink
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            mf.addedge(get(i,j,h-1,false),T,1);
        }
    }

    // Connect a node to itself if it's not flooded
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int t = 0; t < h; t++) {
                if(grid[i][j] > water[t]) {
                    mf.addedge(get(i,j,t,true),get(i,j,t,false),1);
                }
            }
        }
    }

    // Up, down, left, right, stay
    vector<int> dx = {-1,1,0,0,0};
    vector<int> dy = {0,0,1,-1,0};

    // Connect in all 5 ways for each time
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int t = 0; t < h-1; t++) {
                for(int l = 0; l < dx.size(); l++) {
                    int ni = i+dx[l];
                    int nj = j+dy[l];
                    if(inrange(ni,nj)) {
                        mf.addedge(get(i,j,t,false),get(ni,nj,t+1,true),1);
                    }
                }
            }
        }
    }

    cout << mf.getflow() << endl;
}
