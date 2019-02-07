#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct compare {
    bool operator()(const pair<ll,ll>& p1, const pair<ll,ll>& p2) {
        if(p1.first == p2.first) {
            return p1.second > p2.second;
        }
        return p1.first > p2.first;
    }
};

bool cmp(const pair<ll,ll>& p1, const pair<ll,ll>& p2) {
    if(p1.second == p2.second) {
        return p1.first > p2.first;
    }
    return p1.second < p2.second;
}

void solve() {
    ll n;
    cin >> n;
    vector<pair<ll,ll>> v(n);
    for(auto& i : v) {
        cin >> i.first >> i.second;
    }

    multiset<pair<ll,ll>,compare> s;

    sort(v.begin(),v.end(),cmp);

    // We know all inserted before us have a lower second val
    for(auto i : v) {
        // Remove from s if possible
        auto it = s.lower_bound({i.first-1,i.second-1});
        if(it != s.end()) {
            pair<ll,ll> p = *it;
            if(p.first < i.first && p.second < i.second) {
                s.erase(it);
            }
        }
        s.insert(i);
    }

    cout << s.size() << endl;
}

int main() {
    ll cases;
    cin >> cases;
    while(cases--) {
        solve();
    }
}
