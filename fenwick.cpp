#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void update(vector<ll>& v, ll index, ll value) {
    for(ll i = index; i < v.size(); i |= i+1) {
        v[i] += value;
    }
}

ll sum(vector<ll>& v, ll index) {
    ll total = 0;
    for(ll i = index; i > 0; i &= i-1) {
        total += v[i-1];
    }
    return total;
}

int main() {
    ll n, q;
    cin >> n >> q;

    vector<ll> v;
    v.resize(n, 0);

    for(ll i = 0; i < q; i++) {
        char op;
        cin >> op;

        if(op == '+') {
            ll index, value;
            cin >> index >> value;
            update(v, index, value);
        }
        if(op == '?') {
            ll index;
            cin >> index;
            cout << sum(v, index) << endl;
        }
    }
}
