#include <iostream>

using namespace std;

int getDigits(int n) {
    int sum = 0;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int min, max, digits;
    cin >> min >> max >> digits;

    for(int i = min; i <= max; i++) {
        if(getDigits(i) == digits) {
            cout << i << endl;
            break;
        }
    }

    for(int i = max; i >= min; i--) {
        if(getDigits(i) == digits) {
            cout << i << endl;
            break;
        }
    }
}
