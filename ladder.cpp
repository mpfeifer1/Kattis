#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    cout << ceil(a / sin(b * M_PI / 180)) << endl;
}
