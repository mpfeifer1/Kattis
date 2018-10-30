#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<pair<ll,ll>,pair<ll,ll>> op;

const ll Max = 707;
ll height[Max][Max];
ll rate[Max][Max];
ll p[Max*Max];

ll POS;
pair<ll,ll> empty = {-1,-1};
pair<ll, ll> changes[Max*Max*100];

ll find(ll x, bool record = false) {
    if(p[x] < 0) return x;
    if(record)
        changes[POS++] = {x, p[x]};
    return p[x] = find(p[x], record);
}

ll res = 1;
void merge(ll x, ll y, bool record = false) {
    if((x=find(x, record)) == (y=find(y, record))) {
        return;
    }
    if(p[y] < p[x]) swap(x, y);
    if(record) {
        changes[POS++] = {x, p[x]};
        changes[POS++] = {y, p[y]};
    }
    p[x] += p[y];
    p[y] = x;
    res = max(res, -p[x]);
}

void normalize(pair<ll, ll> &time) {
    if(time.second < 0) {
        time.first = -time.first;
        time.second = -time.second;
    }
    ll GCD = __gcd(abs(time.first), abs(time.second));
    if(GCD != 0) {
        time.first /= GCD;
        time.second /= GCD;
    }
}

pair<ll,ll> gettime(ll i, ll j, bool joindown) {
    ll nexti = i;
    ll nextj = j;
    if(joindown) nexti = i - 1;
    else nextj = j - 1;

    if(height[i][j] == height[nexti][nextj] && rate[i][j] == rate[nexti][nextj]) return empty;
    pair<ll, ll> time = {height[i][j] - height[nexti][nextj], rate[nexti][nextj] - rate[i][j]};
    normalize(time);
    if(time.first < 0) return empty;
    if(time.second == 0) return empty;
    return time;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin >> n;

    // Read in input
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            cin >> height[i][j];
        }
    }
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            cin >> rate[i][j];
        }
    }

    // Initialize disjoint set
    for(ll i = 0; i < n*n+1; ++i) {
        p[i] = -1;
    }

    // Join all trees that are the same
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            if(j > 0) {
                if(height[i][j] == height[i][j-1] && rate[i][j] == rate[i][j-1]) {
                    merge(n*i+j, n*i+j-1);
                }
            }
            if(i > 0) {
                if(height[i][j] == height[i-1][j] && rate[i][j] == rate[i-1][j]) {
                    merge(n*i+j, n*(i-1)+j);
                }
            }
        }
    }

    // For each time, find all its ops
    map<pair<ll,ll>, vector<op>> time_to_op;

    // Add new times
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            if(j > 0) {
                pair<ll,ll> time = gettime(i, j, false);
                if(time != empty) {
                    time_to_op[time].push_back({{i,j}, {i,j-1}});
                }
            }
            if(i > 0) {
                pair<ll,ll> time = gettime(i, j, true);
                if(time != empty) {
                    time_to_op[time].push_back({{i,j}, {i-1,j}});
                }
            }
        }
    }

    // Given all merges, find answer
    for(auto& time : time_to_op) {
        POS = 0;
        // Check time
        for(auto& ops : time.second) {
            ll i1 = ops.first.first;
            ll j1 = ops.first.second;
            ll i2 = ops.second.first;
            ll j2 = ops.second.second;
            merge(n*i1+j1, n*i2+j2, true);
        }
        // Undo changes
        for(ll j = POS-1; j >= 0; --j) {
            p[changes[j].first] = changes[j].second;
        }
        POS = 0;
    }
    cout << res << endl;
    return 0;
}
