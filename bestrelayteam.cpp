#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct runner {
    string name;
    double first;
    double second;
};

bool cmp(runner lhs, runner rhs) {
    return lhs.second < rhs.second;
}

pair<vector<string>, double> rest(vector<runner> v, int skip) {
    vector<string> ans;
    ans.push_back(v[skip].name);
    double total = v[skip].first;

    v.erase(v.begin()+skip);

    sort(v.begin(), v.end(), cmp);

    total += v[0].second;
    total += v[1].second;
    total += v[2].second;

    ans.push_back(v[0].name);
    ans.push_back(v[1].name);
    ans.push_back(v[2].name);

    pair<vector<string>, double> p = {ans, total};

    return p;
}

int main() {
    int n;
    cin >> n;

    vector<runner> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].name >> v[i].first >> v[i].second;
    }

    double best = 10000;
    vector<string> bestteam = {};
    for(int i = 0; i < n; i++) {
        pair<vector<string>, double> here = rest(v, i);
        if(here.second < best) {
            best = here.second;
            bestteam = here.first;
        }
    }

    cout << fixed;
    cout.precision(10);
    cout << best << endl;
    for(auto i : bestteam) {
        cout << i << endl;
    }
}
