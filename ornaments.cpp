#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double r, h, s;
    while(cin >> r >> h >> s && !(s == 0 && h == 0 && r == 0)) {
        double total = 0;

        // Calculate the straight edges
        double x = sqrt(pow(h, 2) - pow(r, 2));
        total += 2 * x;

        // Calculate the round bottom
        double angle = 360 - 2 * acos(r/h) * (180 / M_PI);
        total += 2 * M_PI * (angle/360) * r;

        // Add the string to tie
        total += total * (s / 100);

        cout << fixed;
        cout.precision(2);
        cout << total << endl;
    }
}
