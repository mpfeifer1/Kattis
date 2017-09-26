#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

// Generates each combination
vector<bool> get_use(int i, int n) {
    vector<bool> v;
    v.resize(n, false);

    int count = 0;

    while(i > 0) {
        if(i%2 == 1) {
            v[count] = true;
        }
        count++;
        i /= 2;
    }

    return v;
}

// Finds the bitterness and sourness
ll calculate(vector<pair<ll, ll>> v, vector<bool> b) {
    ll sourness = 1;
    ll bitterness = 0;

    for(int i = 0; i < v.size(); i++) {
        if(b[i]) {
            sourness *= v[i].first;
            bitterness += v[i].second;
        }
    }

    return abs(bitterness - sourness);
}

int main() {
    int n;
    cin >> n;

    // Read in data
    vector<pair<ll, ll>> v;
    for(int i = 0; i < n; i++) {
        pair<ll, ll> p;
        cin >> p.first >> p.second;
        v.push_back(p);
    }

    // Find minimum diff
    long long diff = 1000000001;
    for(int i = 1; i < pow(2, n); i++) {
        vector<bool> use = get_use(i, n);
        diff = min(calculate(v, use), diff);
    }

    // Return
    cout << diff << endl;
}
