#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll process(vector<ll>& v) {
    vector<ll> doubled;
    vector<ll> missing;

    for(int i = 1; i < v.size(); i++) {
        if(v[i] == 0) {
            missing.push_back(i);
        }

        for(int j = v[i]; j > 1; j--) {
            doubled.push_back(i);
        }
    }

    ll total = 0;
    for(int i = 0; i < doubled.size(); i++) {
        total += abs(doubled[i] - missing[i]);
    }
    return total;
}

int main() {
    ll n;
    cin >> n;

    vector<ll> hz, vt;
    hz.resize(n+1, 0);
    vt.resize(n+1, 0);

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        hz[x]++;
        vt[y]++;
    }

    ll total = 0;
    total += process(hz);
    total += process(vt);

    cout << total << endl;
}
