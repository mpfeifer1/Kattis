#include <bits/stdc++.h>

using namespace std;

int manhattan(int x1, int y1, int x2, int y2) {
    return abs(x1-x2) + abs(y1-y2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    int px, py;
    cin >> px >> py;

    vector<int> dist(2000002, 0);

    for(int i = 0; i < n; i++) {
        vector<int> x(2);
        vector<int> y(2);
        cin >> x[0] >> y[0] >> x[1] >> y[1];
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        if(x[0] <= px && px <= x[1]) {
            x.push_back(px);
        }
        if(y[0] <= py && py <= y[1]) {
            y.push_back(py);
        }

        vector<int> dists;
        for(auto j : x) {
            for(auto k : y) {
                dists.push_back(manhattan(j, k, px, py));
            }
        }
        sort(dists.begin(), dists.end());

        if(dists.front() <= 2000001) {
            dist[dists.front()]++;
        }
        if(dists.back() <= 2000000) {
            dist[dists.back()+1]--;
        }
    }

    int sum = 0;
    for(int i = 0; i < dist.size(); i++) {
        sum += dist[i];
        dist[i] = sum;
    }

    for(int i = 0; i < q; i++) {
        int t;
        cin >> t;
        cout << dist[t] << endl;
    }
}
