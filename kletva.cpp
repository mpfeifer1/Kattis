#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = 10000000001;
typedef vector<pair<ll,ll>> key;

// Shifts a key down as far as it will go
key shift(key k) {
    ll lo = inf;
    for(auto& i : k) {
        lo = min(lo, i.first);
    }
    for(auto& i : k) {
        i.first -= lo;
        i.second += lo;
    }
    return k;
}

// Flips key from top to bottom
key fliptb(key k) {
    for(auto& i : k) {
        swap(i.first, i.second);
    }
    return k;
}

// Flips key from left to right
key fliplr(key k) {
    reverse(k.begin(), k.end());
    return k;
}

// Generates all 4 possible keys, returns lowest of all such keys
key getkey(key k, ll w) {
    key k1 = shift(k);
    key k2 = shift(fliptb(k));
    key k3 = shift(fliplr(k));
    key k4 = shift(fliptb(fliplr(k)));

    return min({k1,k2,k3,k4});
}

int main() {
    ll w, l, n;
    cin >> w >> l >> n;

    set<key> keys;
    for(int i = 0; i < n; i++) {
        key input(l);
        for(auto& i : input) cin >> i.first;
        for(auto& i : input) cin >> i.second;
        keys.insert(getkey(input, w));
    }

    cout << keys.size() << endl;
}
