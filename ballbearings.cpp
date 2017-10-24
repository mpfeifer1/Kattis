#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    while(n--) {
        double big, small, space;
        cin >> big >> small >> space;

        double l = (big - small) / 2;

        double angle1 = acos((-pow(small+space, 2) + (2*pow(l, 2))) / (2*pow(l, 2))) * 180/M_PI;

        cout << fixed;
        cout.precision(0);
        cout << floor(360 / angle1) << endl;
    }
}

