#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void gcd(vector<ll>& v) {
    vector<ll> next;
    for(ll i = 1; i < v.size(); i++) {
        next.push_back(__gcd(v[i-1],v[i]));
    }
    v = next;
}

void merge(vector<ll>& v) {
    vector<ll> next;
    next.push_back(v[0]);
    for(ll i = 1; i < v.size(); i++) {
        if(v[i] != next.back()) {
            next.push_back(v[i]);
        }
    }
    v = next;
}

int main() {
    ll n;
    cin >> n;

    vector<ll> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    set<ll> all;
    while(true) {
        for(auto& i : v) {
            all.insert(i);
        }
        gcd(v);
        merge(v);
        for(auto& i : v) {
            all.insert(i);
        }
        if(v.size() == 1) break;
    }

    cout << all.size() << endl;
}
