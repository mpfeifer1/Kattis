#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    // Speed up input
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Initialize memo array
    vector<vector<ll>> v;
    v.resize(101, vector<ll>(101));

    // Build edges of memo array
    for(int i = 0; i < 101; i++) {
        v[i][0] = 1;
        v[0][i] = 1;
    }

    // Build center of memo array
    int mod = 1001113;
    for(int i = 1; i < 101; i++) {
        for(int j = 1; j < 101; j++) {
            v[i][j] = v[i-1][j] * (j+1) + v[i][j-1] * (i+1);
            v[i][j] %= mod;
        }
    }

    // For each case,
    int cases;
    cin >> cases;
    while(cases--) {
        int garbo, a, b;
        cin >> garbo >> a >> b;

        // Print memo
        cout << garbo << " " << v[a-b-1][b] << endl;;
    }
}
