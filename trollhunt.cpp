#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int b, k, g;
    cin >> b >> k >> g;

    b--;
    int groups = k / g;
    int days = ceil(double(b) / groups);

    cout << days << endl;
}
