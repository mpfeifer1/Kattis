#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll SIZE;
ll inf = 1 << 30;

ll bfs(vector<vector<ll>>& og, vector<vector<ll>>& rg, vector<ll>& par, ll s, ll t, ll n) {
    vector<ll> f(SIZE, 0);

    vector<bool> visited(SIZE, false);
    visited[s] = true;

    queue<ll> q;
    q.push(s);
    par[s] = -1;
    f[s] = inf;

    while(!q.empty()) {
        ll u = q.front();
        q.pop();
        for(ll v = 0; v < n; v++) {
            if(visited[v] == false && rg[u][v] > 0) {
                q.push(v);
                par[v] = u;
                visited[v] = true;
                f[v] = min(f[u], rg[u][v]);
            }
        }
    }

    if(visited[t]) {
        return f[t];
    }
    return 0;
}

// Takes in original graph, residual graph, source, sink, #nodes
ll fulkerson(vector<vector<ll>>& og, vector<vector<ll>>& rg, ll s, ll t, ll n) {
    ll max_flow = 0, path_flow = 0;

    vector<ll> par(SIZE);

    while(path_flow = bfs(og, rg, par, s, t, n)) {
        for(ll v = t; v != s; v = par[v]) {
            ll u = par[v];
            rg[u][v] -= path_flow;
            rg[v][u] += path_flow;
        }
        max_flow += path_flow;
    }

    return max_flow;
}

ll n, m, c;

ll coord(ll i, ll j, ll graph) {
    ll pos = i*n+j;
    if(graph == 2) pos += n*m;
    return pos;
}

bool inrange(ll i, ll j) {
    return i >= 0 && j >= 0 && i < m && j < n;
}

int main() {
    cin >> n >> m >> c;

    vector<string> board(m);
    for(auto& i : board) {
        cin >> i;
    }

    vector<ll> cost(c);
    for(auto& i : cost) {
        cin >> i;
    }

    SIZE = n * m * 2 + 2;

    ll s = SIZE-2;
    ll t = SIZE-1;

    // Set up original graph and residual graph
    vector<vector<ll>> og, rg;
    og.resize(SIZE, vector<ll>(SIZE, 0));

    vector<ll> dx = {0,0,1,-1};
    vector<ll> dy = {1,-1,0,0};

    for(ll i = 0; i < m; i++) {
        for(ll j = 0; j < n; j++) {
            ll n1 = coord(i,j,1);
            ll n2 = coord(i,j,2);

            if(board[i][j] == 'B') {
                og[s][n2] = inf;
            }
            else if(board[i][j] == '.') {
                og[n1][n2] = inf;
            }
            else {
                og[n1][n2] = cost[board[i][j]-'a'];
            }

            for(ll k = 0; k < 4; k++) {
                ll ix = i + dx[k];
                ll iy = j + dy[k];
                if(inrange(ix,iy)) {
                    og[n2][coord(ix,iy,1)] = inf;
                }
                else {
                    og[n2][t] = inf;
                }
            }
        }
    }

    rg.resize(SIZE, vector<ll>(SIZE, 0));
    for(ll i = 0; i < SIZE; i++) {
        for(ll j = 0; j < SIZE; j++) {
            rg[i][j] = og[i][j];
        }
    }

    ll val = fulkerson(og, rg, s, t, SIZE);
    if(val >= inf) val = -1;
    cout << val << endl;
}
