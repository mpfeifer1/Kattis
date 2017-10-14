#include <iostream>
#include <cmath>

using namespace std;

double PI = M_PI;

int dist(double x, double y) {
    double total = pow(x, 2) + pow(y, 2);
    total = sqrt(total);
    return round(total);
}

int main() {
    int cases;
    cin >> cases;

    for(int i = 0; i < cases; i++) {
        double x = 0;
        double y = 0;

        int angle = 0;

        int commands;
        cin >> commands;

        for(int j = 0; j < commands; j++) {
            string cmd;
            int dist;
            cin >> cmd >> dist;

            if(cmd == "lt") {
                angle += dist;
            }
            if(cmd == "rt") {
                angle -= dist;
            }

            if(cmd == "fd") {
                x += dist * sin(angle * (PI / 180));
                y += dist * cos(angle * (PI / 180));
            }
            if(cmd == "bk") {
                x -= dist * sin(angle * (PI / 180));
                y -= dist * cos(angle * (PI / 180));
            }
        }

        cout << dist(x, y) << endl;
    }
}
