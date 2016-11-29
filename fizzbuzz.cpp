#include <iostream>

using namespace std;

int main() {
    int i, j, k;
    cin >> i >> j >> k;
    for(int m = 1; m <= k; m++) {
        if(m % i == 0 && m%j == 0) {
            cout << "FizzBuzz" << endl;
        }
        else if(m % i == 0) {
            cout << "Fizz" << endl;
        }
        else if(m % j == 0) {
            cout << "Buzz" << endl;
        }
        else {
            cout << m << endl;
        }
    }
}
