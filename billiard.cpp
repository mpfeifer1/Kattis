#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, s, m, n;
    while(cin >> a >> b >> s >> m >> n) {
        if(a == 0 && b == 0 && s == 0 && m == 0 && n == 0) {
            break;
        }

        double xDist = a * m;
        double yDist = b * n;

        double angle = atan(yDist / xDist) * 180 / M_PI;
        double dist = sqrt(pow(xDist, 2) + pow(yDist, 2));

        cout << fixed;
        cout.precision(2);
        cout << angle << " " << dist / s << endl;
    }
}
