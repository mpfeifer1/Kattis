#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
void update(vector<ll>& v, int index, ll value) {
    index++;
    while(index < n+5) {
        v[index] ^= value;
        index += index & (-index);
    }
}

ll sum(vector<ll>& v, int index) {
    ll total = 0;
    index++;
    while(index > 0) {
        total ^= v[index];
        index -= index & (-index);
    }
    return total;
}

int c = 1;
int dfs(vector<vector<int>>& adj, vector<int>& size, vector<int>& order, int curr) {
    order[curr] = c;
    c++;
    size[curr] = 1;
    for(auto next : adj[curr]) {
        size[curr] += dfs(adj, size, order, next);
    }
    return size[curr];
}

int count(ll n) {
    int c = 0;
    while(n > 0) {
        if(n % 2 == 1) {
            c++;
        }
        n >>= 1;
    }
    return c;
}

void print(ll n) {
    vector<int> bits;
    while(n > 0) {
        if(n % 2 == 1) {
            bits.push_back(1);
        }
        else {
            bits.push_back(0);
        }
        n >>= 1;
    }

    reverse(bits.begin(), bits.end());
    for(auto i : bits) {
        cout << i;
    }
    cout << endl;
}

int countnodes(vector<int>& order, vector<int>& size, vector<ll>& lotree, vector<ll>& hitree, int curr) {
    int lo = order[curr];
    int hi = order[curr] + size[curr];

    ll loval1 = sum(lotree, hi-1);
    ll loval2 = sum(lotree, lo-1);
    loval1 ^= loval2;

    ll hival1 = sum(hitree, hi-1);
    ll hival2 = sum(hitree, lo-1);
    hival1 ^= hival2;

    int bits = 0;
    bits += count(loval1);
    bits += count(hival1);

    return bits;
}

void colornodes(vector<int>& order, vector<int>& color, vector<ll>& lotree, vector<ll>& hitree, int curr, int newcolor) {
    int oldcolor = color[curr];
    color[curr] = newcolor;
    curr = order[curr];

    if(oldcolor <= 55) {
        update(lotree,curr,(ll)1<<oldcolor);
    }
    else {
        update(hitree,curr,(ll)1<<(oldcolor-55));
    }

    if(newcolor <= 55) {
        update(lotree,curr,(ll)1<<newcolor);
    }
    else {
        update(hitree,curr,(ll)1<<(newcolor-55));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int q;
    cin >> n >> q;

    // Allocate memory
    vector<vector<int>> adj(n+5);
    vector<int> color(n+5, 0);

    // Read in all colors;
    for(int i = 1; i <= n; i++) {
        cin >> color[i];
    }

    // Read in adjacency list
    for(int i = 2; i <= n; i++) {
        int par;
        cin >> par;
        adj[par].push_back(i);
    }

    // Get all nodes' dfs order
    vector<int> order(n+5, 0);
    vector<int> size(n+5, 0);
    dfs(adj, size, order, 1);

    vector<ll> lotree(n+5,0);
    vector<ll> hitree(n+5,0);

    // Insert each order into the sets of colors
    for(int i = 1; i <= n; i++) {
        if(color[i] <= 55) {
            update(lotree,order[i],(ll)1<<color[i]);
        }
        else {
            update(hitree,order[i],(ll)1<<(color[i]-55));
        }
    }

    // Process each query
    for(int i = 0; i < q; i++) {
        int type, node;
        cin >> type >> node;

        // Count all in subtree
        if(type == 0) {
            int res = countnodes(order, size, lotree, hitree, node);
            cout << res << endl;
        }

        // Change a color
        else {
            colornodes(order, color, lotree, hitree, node, type);
        }
    }
}
