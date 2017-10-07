#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

ll count(set<pair<ll, ll>>& s, pair<ll, ll> point) {
    int total = 0;
    vector<pair<ll, ll>> a;
    a.push_back({point.first + 0,    point.second + 2018});
    a.push_back({point.first + 1118, point.second + 1680});
    a.push_back({point.first + 1680, point.second + 1118});
    a.push_back({point.first + 2018, point.second + 0});
    a.push_back({point.first + 0,    point.second - 2018});
    a.push_back({point.first + 1118, point.second - 1680});
    a.push_back({point.first + 1680, point.second - 1118});

    for(auto i : a) {
        if(s.count(i) > 0) {
            total++;
        }
    }

    return total;
}

int main() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v;
    set<pair<ll, ll>> s;

    for(int i = 0; i < n; i++) {
        pair<ll, ll> p;
        cin >> p.first >> p.second;

        v.push_back(p);
        s.insert(p);
    }

    sort(v.begin(), v.end());

    ll total = 0;
    for(auto i : v) {
        total += count(s, i);
        s.erase(i);
    }

    cout << total << endl;
}
