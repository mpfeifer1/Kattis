#include <iostream>
#include <cmath>

using namespace std;

double DtoR(double a) {
    return a * M_PI / 180;
}

double RtoD(double a) {
    return a / 180 * M_PI;
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int segments;
        cin >> segments;
        double x = 0, y = 0;
        double angle = 90;

        for(int j = 0; j < segments; j++) {
            double a, d;
            cin >> a >> d;

            angle += a;
            x += d * cos(DtoR(angle));
            y += d * sin(DtoR(angle));
        }

        cout << fixed;
        cout.precision(6);
        cout << x << " " << y << endl;
    }
}
