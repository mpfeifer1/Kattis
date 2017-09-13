#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

struct color {
    double x;
    double y;
    double v;
    string col;
};

double getdistance(double x, double y, color k) {
    return sqrt(pow(x-k.x,2) + pow(y-k.y,2));
}

double inrange(double dist, color k) {
    return dist < sqrt(k.v / M_PI);
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int c;
        cin >> c;
        vector<color> v;
        for(int j = 0; j < c; j++) {
            color temp;
            cin >> temp.x >> temp.y >> temp.v >> temp.col;
            v.push_back(temp);
        }

        int d;
        cin >> d;

        for(int j = 0; j < d; j++) {
            string closest = "white";

            double x, y;
            cin >> x >> y;

            for(auto k : v) {
                double dist = getdistance(x, y, k);
                if(inrange(dist, k)) {
                    closest = k.col;
                }
            }

            cout << closest << endl;
        }
    }
}
