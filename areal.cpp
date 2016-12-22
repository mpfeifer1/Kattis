#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long int area;
    cin >> area;

    cout.precision(8);
    cout << fixed << sqrt(area) * 4 << endl;
}
