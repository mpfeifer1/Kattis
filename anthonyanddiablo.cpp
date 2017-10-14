#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double d1, d2;
    cin >> d1 >> d2;

    double c = 2 * M_PI * sqrt(d1 / M_PI);

    if(c - d2 <= 0) {
        cout << "Diablo is happy!" << endl;
    }
    else {
        cout << "Need more materials!" << endl;
    }
}

