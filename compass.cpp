#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    b -= a;
    if(b <= -180) {
        b += 360;
    }
    if(b > 180) {
        b -= 360;
    }
    cout << b << endl;
}
