#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string tostr(ll n) {
    string s;
    while(n > 0) {
        s.push_back(n%2+'0');
        n >>= 1;
    }
    return s;
}

ll toint(string s) {
    ll ans = 0;
    for(auto i : s) {
        ans <<= 1;
        if(i == '1') {
            ans++;
        }
    }
    return ans;
}

ll gen1(ll i) {
    string s, t;
    s = t = tostr(i);
    reverse(t.begin(), t.end());
    string end = t + s;
    return toint(end);
}

ll gen2(ll i) {
    string s, t;
    s = t = tostr(i);
    reverse(t.begin(), t.end());
    string end = t + '1' + s;
    return toint(end);
}

ll gen3(ll i) {
    string s, t;
    s = t = tostr(i);
    reverse(t.begin(), t.end());
    string end = t + '0' + s;
    return toint(end);
}

int main() {
    ll n;
    cin >> n;

    set<ll> s;
    s.insert(0);
    s.insert(1);

    for(ll i = 0; i < 50000; i++) {
        s.insert(gen1(i));
        s.insert(gen2(i));
        s.insert(gen3(i));
    }

    for(ll i = 0; i < n; i++) {
        s.erase(*s.begin());
    }

    cout << *s.begin() << endl;
}
