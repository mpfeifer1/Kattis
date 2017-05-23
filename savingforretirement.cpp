#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int b, br, bs, a, as;
    cin >> b >> br >> bs >> a >> as;

    int bobMoney = (br - b) * bs;
    int aliceYears = ceil(double(bobMoney)/double(as));

    if(bobMoney == aliceYears * as) {
        aliceYears++;
    }

    cout << aliceYears + a << endl;
}
