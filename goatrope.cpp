#include <bits/stdc++.h>

using namespace std;

double dist(pair<int,int> p1, pair<int,int> p2) {
    double d1 = pow(p1.first - p2.first,2);
    double d2 = pow(p1.second - p2.second,2);
    return sqrt(d1 + d2);
}

int main() {
    int gx, gy;
    int hx1, hy1, hx2, hy2;

    cin >> gx >> gy;
    cin >> hx1 >> hy1 >> hx2 >> hy2;

    vector<pair<int,int>> check;
    double best = 1000000;

    check.push_back({hx1, hy1});
    check.push_back({hx2, hy1});
    check.push_back({hx1, hy2});
    check.push_back({hx2, hy2});

    if(hx1 < gx && gx < hx2) {
        check.push_back({gx, hy1});
        check.push_back({gx, hy2});
    }
    if(hy1 < gy && gy < hy2) {
        check.push_back({hx1, gy});
        check.push_back({hx2, gy});
    }

    for(auto i : check) {
        best = min(best, dist({gx, gy}, i));
    }

    cout << fixed;
    cout.precision(6);
    cout << best << endl;
}
