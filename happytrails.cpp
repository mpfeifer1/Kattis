#include <iostream>
#include <cmath>

using namespace std;

typedef long double ld;

int main() {
    int segments;
    cin >> segments;

    ld height = 0;
    while(segments--) {
        ld angle, dist;
        cin >> angle >> dist;

        height += sin(angle * M_PI / 180) * dist;
    }

    cout << fixed;
    cout.precision(2);
    cout << height << endl;
}
