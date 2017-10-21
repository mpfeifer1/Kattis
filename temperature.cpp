#include <iostream>

using namespace std;

int main() {
    double a, b;
    cin >> a >> b;

    b--;

    if(b < .5) {
        if(a == 0) {
            cout << "ALL GOOD" << endl;
        }
        else {
            cout << "IMPOSSIBLE" << endl;
        }
    }

    else {
        cout << fixed;
        cout.precision(9);
        cout << - (a / b) << endl;
    }
}
