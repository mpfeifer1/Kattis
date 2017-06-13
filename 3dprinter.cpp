#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double n;
    cin >> n;

    n = log2(n);
    n = ceil(n);
    n++;

    cout << n << endl;
}
