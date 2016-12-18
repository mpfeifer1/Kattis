#include <iostream>

using namespace std;

int main() {
    int C, R;
    cin >> R >> C;
    C = R - C;

    long double out = R * R;
    long double in  = C * C;

    cout.precision(10);
    cout << in / out * 100.0 << endl;
}
