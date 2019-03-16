#include <bits/stdc++.h>

using namespace std;

int dist(pair<int,int> p1, pair<int,int> p2) {
    return abs(p1.first-p2.first) +
        abs(p1.second-p2.second);
}

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> s;
    vector<pair<int,int>> h;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char c;
            cin >> c;

            if(c == 'S') s.push_back({i,j});
            if(c == 'H') h.push_back({i,j});
        }
    }

    int ans = 0;
    for(int i = 0; i < s.size(); i++) {
        int d = 100000;
        for(int j = 0; j < h.size(); j++) {
            d = min(d,dist(s[i],h[j]));
        }
        ans = max(ans,d);
    }

    cout << ans << endl;
}
