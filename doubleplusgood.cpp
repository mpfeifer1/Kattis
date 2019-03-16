#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    vector<ll> v;
    ll i;
    while(cin >> i) {
        v.push_back(i);
    }

    set<ll> nums;

    for(ll i = 0; i < (1 << (v.size()-1)); i++) {
        ll total = 0;
        ll curr = 0;

        curr = v[0];
        for(ll j = 1; j < v.size(); j++) {
            if(i & (1<<(j-1))) {
                total += curr;
                curr = v[j];
            }
            else {
                string t = to_string(curr) + to_string(v[j]);
                ll i = stoll(t);
                curr = i;
            }
        }
        total += curr;
        nums.insert(total);
    }

    cout << nums.size() << endl;
}
