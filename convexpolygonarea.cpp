#include <iostream>
#include <vector>

using namespace std;

int main() {
    int cases;
    cin >> cases;

    for(int i = 0; i < cases; i++) {
        int points;
        cin >> points;

        vector<pair<int, int>> v;
        for(int j = 0; j < points; j++) {
            pair<int, int> p;
            cin >> p.first >> p.second;
            v.push_back(p);
        }

        double result = 0;

        for(int i = 0, j = 1, n = v.size(); i < n; i++, j = (i+1) % n) {
            result += (v[i].first * v[j].second) - (v[i].second * v[j].first);
        }

        cout << result / 2 << endl;
    }
}
