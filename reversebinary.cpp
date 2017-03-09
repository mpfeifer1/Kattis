#include <iostream>

using namespace std;

int main() {
    unsigned long long a = 0, b = 0;
    cin >> a;
    while(a != 0) {
        b <<= 1;
        if(a % 2 == 1) {
            b++;
        }
        a >>= 1;
    }
    cout << b << endl;
}
