#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double d;
    cin >> d;

    cout << fixed;
    cout.precision(6);

    cout << pow(d, (1/d)) << endl;
}

