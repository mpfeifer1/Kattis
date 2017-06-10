#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int dist(int a, int b, vector<pair<double, double>> v) {
    double xdist, ydist;
    xdist = v[a].first - v[b].first;
    ydist = v[a].second - v[b].second;

    double d = sqrt(pow(xdist, 2) + pow(ydist, 2));
    return round(d);
}

int main() {
    vector<pair<double, double>> v;

    double n;
    cin >> n;

    for(int i = 0;  i < n; i++) {
        double x, y;
        cin >> x >> y;

        v.push_back({x, y});
    }

    vector<int> tour;
    vector<bool> used;

    tour.resize(n, -1);
    used.resize(n, false);

    tour[0] = 0;
    used[0] = true;

    for(int i = 1; i < n; i++) {
        int best = -1;
        for(int j = 0; j < n; j++) {
            if(!used[j] && (best == -1 || dist(tour[i-1], j, v) < dist(tour[i-1], best, v))) {
                best = j;
            }
        }
        tour[i] = best;
        used[best] = true;
    }

    for(auto i : tour) {
        cout << i << endl;
    }
}
