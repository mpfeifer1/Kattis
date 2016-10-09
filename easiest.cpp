#include <iostream>

using namespace std;

int getDigits(int num);

int main() {
    int i;// The number that the user entered
    cin >> i;
    while(i != 0) {
        int j = 11;
        while(getDigits(i) != getDigits(i * j)) {
            j++;
        }
        cout << j << endl;
        cin >> i;
    }
}

int getDigits(int num) {
    int digits = 0;
    while(num > 0) {
        digits += num % 10;
        num /= 10;
    }
    return digits;
}
