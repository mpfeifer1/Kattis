#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if(b % 2 == 0) {
        cout << "possible" << endl;
    }
    else {
        cout << "impossible" << endl;
    }
}
