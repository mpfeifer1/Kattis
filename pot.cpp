#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int times;
    cin >> times;

    long long total = 0;
    for(int i = 0; i < times; i++) {
        long long temp;
        cin >> temp;
        long long num, exp;
        num = temp / 10;
        exp = temp % 10;
        temp = pow(num, exp);
        total += temp;
    }
    cout << total << endl;
}
