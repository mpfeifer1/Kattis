#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double r, x, y;
    while(cin >> r && cin >> x && cin >> y) {
        double length = sqrt(pow(x, 2) + pow(y, 2));
        if(length >= r) {
            cout << "miss" << endl;
            continue;
        }
        double area = M_PI * pow(r, 2);
        double height = r - length;
        double theta = 2 * acos(1-(height/r));
        double chordArea = (pow(r, 2)/2) * (theta - sin(theta));
        double otherArea = area - chordArea;

        if(chordArea < otherArea) {
            swap(chordArea, otherArea);
        }

        cout.precision(6);
        cout << fixed;
        cout << chordArea << " " << otherArea << endl;
    }
}
