#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll m, n;
ll a, b;
vector<vector<ll>> v;

vector<pair<ll,vector<ll>>> getArrays() {
    // Res contains pairs of {rows, array of mins}
    vector<pair<ll,vector<ll>>> res;

    // For each top row
    for(ll i = 0; i < n; i++) {
        vector<ll> currmin = v[i];
        // For each bottom row
        for(ll j = i; j < n; j++) {
            // Keep track of our running min
            for(ll k = 0; k < m; k++) {
                currmin[k] = min(currmin[k],v[j][k]);
            }

            // Add this array
            res.push_back({j-i+1,currmin});
        }
    }

    // Return all the arrays
    return res;
}

ll calc(ll r, ll c, ll depth) {
    ll top = depth * (n*m);
    ll bot = (n*m) - (r*c);

    assert(bot > 0);

    if(top % bot == 0) {
        return (top / bot - 1) * r * c;
    } 
    return (top / bot) * r * c;
}

ll getval(ll rows, vector<ll>& arr) {


    vector<ll> lefts(m), rights(m);
    stack<ll> positions;
    for(ll i = 0; i < m; ++i) {
        while(!positions.empty() && arr[positions.top()] >= arr[i]) positions.pop();
        if(positions.empty()) {
            lefts[i] = -1;
        } else {
            lefts[i] = positions.top();
        }
        positions.push(i);
    }
    while(!positions.empty()) positions.pop();
    for(ll i = m-1; i >= 0; --i) {
        while(!positions.empty() && arr[positions.top()] >= arr[i]) positions.pop();
        if(positions.empty()) {
            rights[i] = m;
        } else {
            rights[i] = positions.top();
        }
        positions.push(i);
    }



    ll best = 0;
    for(ll i = 0; i < m; i++) {
        ll cols = rights[i] - lefts[i] - 1;
        best = max(best, calc(min(a,rows),min(b,cols),arr[i]));
        best = max(best, calc(min(b,rows),min(a,cols),arr[i]));
    }
    return best;
}

void solve() {
    ll best = 0;
    vector<pair<ll,vector<ll>>> arrs = getArrays();
    int t = 0;
    for(auto& i : arrs) {
        best = max(best,getval(i.first,i.second));
    }
    cout << best << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> a >> b >> n >> m;

    v.resize(n,vector<ll>(m));
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    solve();
}
