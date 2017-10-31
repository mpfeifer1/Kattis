#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

// Increments tree
void inc(vector<ll>& f, ll i, ll d) {
    for(; i < f.size(); i |= i+1) {
        f[i] += d;
    }
}

// Gets count from i down
ll sum(vector<ll>& f, ll i) {
    ll total = 0;
    for(; i > 0; i &= i-1) {
        total += f[i-1];
    }
    return total;
}

// Gets count from i and up
ll count(vector<ll>& f, ll i) {
    return sum(f, f.size()) - sum(f, i);
}

int main() {
    ll n;
    cin >> n;

    vector<ll> f1(n+1, 0);
    vector<ll> f2(n+1, 0);
    vector<ll> f3(n+1, 0);

    for(ll i = 0; i < n; i++) {
        int num;
        cin >> num;
        ll s1 = count(f1, num+1);
        ll s2 = count(f2, num+1);

        inc(f1, num, 1);
        inc(f2, num, s1);
        inc(f3, num, s2);
    }

    cout << count(f3, 0) << endl;
}
