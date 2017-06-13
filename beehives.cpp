#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int pythag(pair<double, double> p1, pair<double, double> p2) {
    double x = p1.first - p2.first;
    double y = p1.second - p2.second;

    return sqrt(pow(x, 2) + pow(y, 2));
}

int main() {
    double dist;
    int hives;
    while(cin >> dist && cin >> hives && !(dist == 0 && hives == 0)) {
        vector<pair<double, double>> v;

        for(int i = 0; i < hives; i++) {
            double x, y;
            cin >> x >> y;
            v.push_back({x, y});
        }

        int sour = 0, sweet = 0;

        for(int i = 0; i < hives; i++) {
            bool fight = false;
            for(int j = 0; j < hives; j++) {
                if(i == j) {
                    continue;
                }
                if(pythag(v[i], v[j]) < dist) {
                    fight = true;
                    break;
                }
            }

            if(fight) {
                sour++;
            }
            else {
                sweet++;
            }
        }

        cout << sour << " sour, " << sweet << " sweet" << endl;
    }
}
