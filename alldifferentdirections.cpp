#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while(cin >> n && n != 0) {
        vector<pair<double, double>> destinations;

        for(int i = 0; i < n; i++) {
            double x, y;
            double angle;
            cin >> x >> y;

            string directions;
            getline(cin, directions);

            stringstream ss(directions);
            string direction;
            double dist;
            while(ss >> direction && ss >> dist) {
                if(direction == "start") {
                    angle = dist;
                }
                if(direction == "walk") {
                    x += dist * cos(angle * M_PI/180);
                    y += dist * sin(angle * M_PI/180);
                }
                if(direction == "turn") {
                    angle += dist;
                }
            }

            pair<double, double> p = {x, y};
            destinations.push_back(p);
        }

        double avgx = 0;
        double avgy = 0;
        for(auto i : destinations) {
            avgx += i.first;
            avgy += i.second;
        }
        avgx /= destinations.size();
        avgy /= destinations.size();

        double maxdist = 0;
        for(int i = 0; i < destinations.size(); i++) {
            double disthere = dist(avgx, avgy, destinations[i].first, destinations[i].second);
            if(disthere > maxdist) {
                maxdist = disthere;
            }
        }

        cout << fixed;
        cout.precision(4);
        cout << avgx << " " << avgy << " " << maxdist << endl;
    }
}
