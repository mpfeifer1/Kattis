#include <iostream>
#include <cmath>

using namespace std;

long long sumdivisors(long long n) {
    long long sum = 0;

    for(int i = 1; i <= sqrt(n); i++) {
        if(n % i == 0) {
            if(i == sqrt(n)) {
                sum += i;
            }
            else {
                sum += i;
                sum += n/i;
            }
        }
    }

    sum -= n;
    return sum;
}

int main() {
    long long n;
    while(cin >> n) {
        long long d = sumdivisors(n);
        if(n == d) {
            cout << n << " perfect" << endl;
        }
        else if(abs(n-d) <= 2) {
            cout << n << " almost perfect" << endl;
        }
        else {
            cout << n << " not perfect" << endl;
        }
    }
}
