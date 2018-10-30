#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;

    vector<ll> child(n);
    ll t = 0;
    for(int i = 0; i < n; i++) {
        cin >> child[i];
        if(i != 0) child[i]--;
        t += child[i];
    }

    ll leaves = 0;
    bool works = true;
    for(int i = n-1; i >= 0; i--) {
        if(child[i] > leaves) works = false;
        leaves -= child[i];
        leaves++;
    }

    if(works && t == n-1) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
