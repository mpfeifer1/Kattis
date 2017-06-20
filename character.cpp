#include <iostream>
#include <cmath>

using namespace std;

int character(int n) {
    if(n == 0 || n == 1) {
        return 0;
    }

    return pow(2, n-1) - 1 + character(n-1);
}

int main() {
    int n;
    cin >> n;

    cout << character(n) << endl;
}
