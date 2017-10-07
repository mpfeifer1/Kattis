#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if(a == 0 && b == 0) {
        cout << "Not a moose" << endl;
        return 0;
    }

    if(a == b) {
        cout << "Even ";
    }
    else {
        cout << "Odd ";
    }

    cout << 2 * max(a, b) << endl;
}
