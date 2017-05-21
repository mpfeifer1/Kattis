#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double D, V;
    while(cin >> D && cin >> V && D != 0 && V != 0) {
        double total = M_PI * pow(D/2, 2) * D;
        double wood = total - V;
        double bigCones = M_PI * pow(D/2,2) * (D/3);
        double shape = wood - bigCones;
        double cylinder = shape * 1.5;
        double r = pow((cylinder / (2 * M_PI)), (1.0/3));

        cout << fixed;
        cout.precision(9);
        cout << r * 2 << endl;
    }
}
