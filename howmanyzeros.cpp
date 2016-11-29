#include <iostream>

using namespace std;

unsigned long long getZeros(unsigned long long num) {
    unsigned long long total = 0;
    while(num > 9) {
        total += num % 10;
        num /= 10;
    }

    unsigned long long extras = 0;
    

    return total;
}

int main() {
    unsigned long long i, j;
    cin >> i >> j;
    while(i != -1 && j != -1) {

        

        cin >> i >> j;
    }
}
