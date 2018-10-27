#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


void generate(vector<pair<int,int>>& v, map<pair<int,int>,int>& m) {
    for(int i = 1; i < (1 << v.size()); i++) {
        pair<int,int> sum = {0,0};
        for(int j = 0; j < v.size(); j++) {
            if((1<<j) & i) {
                sum.first += v[j].first;
                sum.second += v[j].second;
            }
        }
        m[sum]++;
    }
}

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> v1;
    vector<pair<int,int>> v2;

    for(int i = 0; i < n; i++) {
        pair<int,int> p;
        cin >> p.first >> p.second;
        if(i % 2 == 0) {
            v1.push_back(p);
        }
        else {
            v2.push_back(p);
        }
    }

    map<pair<int,int>,int> set1;
    map<pair<int,int>,int> set2;

    generate(v1, set1);
    generate(v2, set2);

    ll ans = 0;
    for(auto i : set1) {
        pair<int,int> p = i.first;
        if(set2.count({-p.first, -p.second})) {
            ans += set1[{p.first,p.second}] * set2[{-p.first,-p.second}];
        }
    }
    ans += set1[{0,0}];
    ans += set2[{0,0}];

    cout << ans << endl;
}
