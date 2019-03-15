#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

vector<vector<ll> > mult(vector<vector<ll> > a, vector<vector<ll> > b) {
    if(a.size() == 0) return {};
    if(a[0].size() == 0) return {};
    if(b.size() == 0) return {};
    if(b[0].size() == 0) return {};
    if(a[0].size() != b.size()) return {};
    int resultRow = a.size(), resultCol = b[0].size(), n = a[0].size();
    vector<vector<ll> > product(resultRow, vector<ll>(resultCol));
    for(int i = 0; i < resultRow; ++i) {
        for(int j = 0; j < resultCol; ++j) {
            product[i][j] = 0;
            for(int k = 0; k < n; ++k) {
                product[i][j] += a[i][k] * b[k][j];
                product[i][j] %= mod;
            }
        }
    }
    return product;
}

vector<vector<ll> > power(vector<vector<ll> > matrix, ll b) {
    if (b <= 1) return matrix;
    vector<vector<ll> > temp = power(matrix, b/2);
    if (b % 2 == 0) return mult(temp, temp);
    return mult(mult(temp, temp), matrix);
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<vector<ll>> ways(51,vector<ll>(51,0));
    for(int i = 0; i < 50; i++) {
        ways[i][i+1]++;
    }

    for(int i = 0; i < k; i++) {
        int t;
        cin >> t;
        ways[t-1][0]++;
    }

    ways = power(ways,n);

    if(ways[0][0]) {
        cout << ways[0][0] << endl;
    }
    else {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        solve();
    }
}
