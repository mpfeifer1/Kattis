#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double zipper(vector<pair<double, double>>& v) {
    double total = 0;

    int n = v.size();
    for(int i = 0, j = 1; i < n; i++, j = (j+1) % n) {
        total += v[i].first * v[j].second;
        total -= v[i].second * v[j].first;
    }

    return total / 2;
}

int main() {
    int n;
    while(cin >> n && n != 0) {
        vector<pair<double, double>> v;
        for(int i = 0; i < n; i++) {
            pair<double, double> p;
            cin >> p.first >> p.second;
            v.push_back(p);
        }

        double ans = zipper(v);
        cout << fixed;
        cout.precision(1);

        if(ans < 0) {
            cout << "CW ";
        }
        else {
            cout << "CCW ";
        }
        cout << abs(ans) << endl;
    }
}
