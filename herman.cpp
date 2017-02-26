#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double i;
    cin >> i;
    cout.precision(8);

    cout << fixed << M_PI * pow(i, 2) << endl;
    cout << fixed << pow(i, 2) * 2 << endl;
}
