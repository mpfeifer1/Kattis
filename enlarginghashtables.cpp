#include <iostream>
#include <cmath>

using namespace std;

bool isprime(int n) {
    if(n == 2) {
        return true;
    }
    for(int i = 2; i < sqrt(n)+1; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    while(cin >> n && n != 0) {
        int copy = n;
        n *= 2;
        n++;
        while(!isprime(n)) {
            n++;
        }

        cout << n;
        if(!isprime(copy)) {
            cout << " (" << copy << " is not prime)";
        }
        cout << endl;

    }
}
