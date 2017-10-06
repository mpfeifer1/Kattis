#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(pair<int, int> lhs, pair<int, int> rhs) {
    if(lhs.second == rhs.second) {
        return lhs.first < rhs.first;
    }
    return lhs.second < rhs.second;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> minions;

    for(int i = 0; i < n; i++) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        minions.push_back(p);
    }

    sort(minions.begin(), minions.end(), cmp);

    int rooms = 1;
    int threshold = minions[0].second;

    for(int i = 1; i < minions.size(); i++) {
        if(minions[i].first > threshold) {
            threshold = minions[i].second;
            rooms++;
        }
    }

    cout << rooms << endl;
}
