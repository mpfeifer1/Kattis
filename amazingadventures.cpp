#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll
const ll inf = (ll)1 << 60;

struct rib {
	int a, b, u, c, f;
	size_t back;
};

void add_rib(vector<vector<rib>>& g, ll a, ll b, ll u, ll c) {
	rib r1 = {a,b,u,c,0,g[b].size()};
	rib r2 = {b,a,0,-c,0,g[a].size()};
	g[a].push_back(r1);
	g[b].push_back(r2);
}

ll n, m, k = inf;

pair<ll,ll> mincostflow(vector<vector<rib>>& g, ll s, ll t) {
	ll flow = 0,  cost = 0;
	while(flow < k) {
		vector<ll> id(n, 0);
		vector<ll> d(n, inf);
		vector<ll> q(n);
		vector<ll> p(n);
		vector<size_t> p_rib(n);
		ll qh=0, qt=0;
		q[qt++] = s;
		d[s] = 0;
		while(qh != qt) {
			ll v = q[qh++];
			id[v] = 2;
			if(qh == n)  qh = 0;
			for(size_t i=0; i<g[v].size(); ++i) {
				rib& r = g[v][i];
				if(r.f < r.u && d[v] + r.c < d[r.b]) {
					d[r.b] = d[v] + r.c;
					if(id[r.b] == 0) {
						q[qt++] = r.b;
						if(qt == n) qt = 0;
					}
					else if(id[r.b] == 2) {
						if(--qh == -1) qh = n-1;
						q[qh] = r.b;
					}
					id[r.b] = 1;
					p[r.b] = v;
					p_rib[r.b] = i;
				}
			}
		}
		if(d[t] == inf) break;
		ll addflow = k - flow;
		for(ll v=t; v!=s; v=p[v]) {
			ll pv = p[v]; size_t pr = p_rib[v];
			addflow = min(addflow, g[pv][pr].u - g[pv][pr].f);
		}
		for(ll v=t; v!=s; v=p[v]) {
			ll pv = p[v]; size_t pr = p_rib[v], r = g[pv][pr].back;
			g[pv][pr].f += addflow;
			g[v][r].f -= addflow;
			cost += g[pv][pr].c * addflow;
		}
		flow += addflow;
	}
    return {flow,cost};
}

vector<int> dx = {1,-1,0,0};
vector<int> dy = {0,0,1,-1};

bool inrange(int n, int m, int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m;
}

int tonode(int n, int i, int j, int layer) {
    return ((n*i+j) << 1) + layer;
}

string getstring(vector<vector<char>>& v, int i, int j) {
    string res = "";
    while(v[i][j] != '?') {
        res.push_back(v[i][j]);
        if(res.back() == 'U') i++;
        else if(res.back() == 'D') i--;
        else if(res.back() == 'L') j--;
        else if(res.back() == 'R') j++;
    }
    return res;
}

int32_t main() {

    int n, m;
    while(cin >> n >> m) {
        if(n == 0 && m == 0) break;

        // Set the size of the graph
        ::n = (n*m*2)+2;
        int s = ::n-1;
        int t = ::n-2;
        vector<vector<rib>> g(::n);

        // Read in input
        pair<int,int> start;
        pair<int,int> mid;
        pair<int,int> end;
        pair<int,int> avoid;

        cin >> start.first >> start.second;
        cin >> mid.first >> mid.second;
        cin >> end.first >> end.second;
        cin >> avoid.first >> avoid.second;

        start.first--; start.second--;
        mid.first--; mid.second--;
        end.first--; end.second--;
        avoid.first--; avoid.second--;

        // Build the graph
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(pair<int,int>(i,j) == avoid) continue;

                // Add edge to itself
                add_rib(g,tonode(m,i,j,0),tonode(m,i,j,1),1,0);

                if(pair<int,int>(i,j) == start) {
                    add_rib(g,s,tonode(m,i,j,0),1,0);
                }
                if(pair<int,int>(i,j) == end) {
                    add_rib(g,s,tonode(m,i,j,0),1,0);
                }
                if(pair<int,int>(i,j) == mid) {
                    add_rib(g,tonode(m,i,j,0),t,2,0);
                }

                for(int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if(pair<int,int>(ni,nj) == avoid) continue;
                    if(!inrange(n,m,ni,nj)) continue;

                    add_rib(g,tonode(m,i,j,1),tonode(m,ni,nj,0),1,1);
                }
            }
        }

        int path = mincostflow(g, s, t).first;
        if(path == 2) {
            cout << "YES" << endl;

            vector<vector<char>> v(n, vector<char>(m,'?'));

            for(auto i : g) {
                for(auto j : i) {
                    int n1 = j.a;
                    int n2 = j.b;

                    if(n1 == s || n2 == s) continue;
                    if(n1 == t || n2 == t) continue;

                    n1 >>= 1;
                    n2 >>= 1;

                    if(n1 == n2) continue;
                    if(j.u != j.f) continue;
                    if(j.f != 1) continue;

                    int i1 = n1 / m;
                    int j1 = n1 % m;

                    int i2 = n2 / m;
                    int j2 = n2 % m;

                    char c = '?';
                    if(i1 < i2) c = 'U';
                    if(i1 > i2) c = 'D';
                    if(j1 < j2) c = 'R';
                    if(j1 > j2) c = 'L';
                    v[i1][j1] = c;
                }
            }

            string s1 = getstring(v,start.first,start.second);
            string s2 = getstring(v,end.first,end.second);
            reverse(s2.begin(),s2.end());
            for(auto& i : s2) {
                if(i == 'U') i = 'D';
                else if(i == 'D') i = 'U';
                else if(i == 'L') i = 'R';
                else if(i == 'R') i = 'L';
            }
            cout << s1 << s2 << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}
