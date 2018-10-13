#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define umap unordered_map
#define uset unordered_set

const ll mod = 1000000007;

ll convert(ll n) {
    if(n == 0) return 1;
    ll ans = 0;
    while(n > 0) {
        ans += ll(1) << ((n%10) << 2);
        n /= 10;
    }
    return ans;
}

bool connected(const ll n1, const ll n2) {
    int up1 = 0;
    for(int i = 0; i < 10; i++) {
        ll n1a = (n1 >> (i << 2)) & 15;
        ll n2a = (n2 >> (i << 2)) & 15;

        ll diff = n2a - n1a;
        if(diff > 1 || diff < 0) {
            return false;
        }
        if(diff == 1) up1++;
    }
    return (up1 == 1);
}

ll solve(umap<ll,vector<ll>>& adj, umap<ll,ll>& count, ll start) {
    map<ll,ll> waysdepth;
    umap<ll,ll> ways;
    umap<ll,ll> depth;
    uset<ll> seen;

    queue<ll> q;
    q.push(start);

    ways[start] = 1;
    depth[start] = 0;

    while(!q.empty()) {
        ll curr = q.front();
        q.pop();

        if(seen.count(curr) > 0) {
            continue;
        }
        seen.insert(curr);

        waysdepth[depth[curr]] += ways[curr];
        waysdepth[depth[curr]] %= mod;

        for(auto next : adj[curr]) {
            if(ways.count(next) == 0) {
                ways[next] = 0;
            }

            depth[next] = depth[curr] + 1;

            ways[next] += (ways[curr] * count[next]) % mod;
            ways[next] %= mod;

            q.push(next);
        }
    }

    return (*prev(waysdepth.end())).second;
}

int main() {
    ll n, m;
    cin >> n >> m;

    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    umap<ll,ll> count;
    uset<ll> seen;

    for(ll i = 0; i < n; i++) {
        if(seen.count(d) == 0) {
            count[convert(d)]++;
        }
        seen.insert(d);
        d = (a * ll(d) + b) % c;
    }

    umap<ll,vector<ll>> adj;
    for(auto i : count) {
        for(auto j : count) {
            if(connected(i.first, j.first)) {
                adj[i.first].push_back(j.first);
            }
        }
    }

    umap<ll,ll> memo;
    for(ll i = 0; i < m; i++) {
        ll q;
        cin >> q;

        ll query = convert(q);

        if(memo.count(query) > 0) {
            cout << memo[query] << endl;
            continue;
        }

        ll ans = solve(adj, count, query);
        memo[query] = ans;
        cout << ans << endl;
    }
}
