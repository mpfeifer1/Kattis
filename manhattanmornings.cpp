#include <bits/stdc++.h>
using namespace std;


// Returns an array with the indexes of the LIS
template <class T>
vector<int> LIS(vector<T>& v) {
    vector<int> p(v.size(), -1);
    vector<int> t(v.size(), 0);

    int lis = 1;
    for(int i = 1; i < v.size(); i++) {
        if(v[i] <= v[t[0]]) {
            t[0] = i;
        }
        else if(v[i] > v[t[lis - 1]]) {
            p[i] = t[lis - 1];
            t[lis++] = i;
        }
        else {
            int l = -1;
            int r = lis - 1;
            while(r - l > 1) {
                int m = l + (r - l) / 2;
                if(v[t[m]] >= v[i]) r = m;
                else l = m;
            }
            p[i] = t[r - 1];
            t[r] = i;
        }
    }

    vector<int> ans;
    for(int i = t[lis - 1]; i >= 0; i = p[i]) {
        ans.push_back(i);
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    // Read input
    int n;
    cin >> n;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    vector<pair<int, int>> points;
    for(int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        if(x > max(x1, x2)) continue;
        if(x < min(x1, x2)) continue;
        if(y > max(y1, y2)) continue;
        if(y < min(y1, y2)) continue;
        points.push_back({x,y});
    }

    // Count real points, edge cases none
    n = points.size();
    if(n == 0) {
        cout << "0\n";
        return 0;
    }

    // Sanitize points
    int currMinY = min(y1, y2);
    for(int i = 0; i < n; ++i) {
        points[i].second -= currMinY;
    }
    y1 -= currMinY;
    y2 -= currMinY;
    if((y1 > y2) ^ (x1 > x2)) {
        swap(y1, y2);
        for(int i = 0; i < n; ++i) {
            points[i].second = abs(y1-y2) - points[i].second;
        }
    }

    // Prepare LIS
    sort(points.begin(), points.end());
    vector<pair<int, int>> yCord;
    for(int i = 0; i < n; ++i) {
        yCord.push_back({points[i].second, i});
    }

    cout << LIS(yCord).size() << '\n';
}


