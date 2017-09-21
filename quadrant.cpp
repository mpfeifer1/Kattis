#include <iostream>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    if(x > 0 && y > 0) {
        cout << 1 << endl;
    }
    if(x < 0 && y > 0) {
        cout << 2 << endl;
    }
    if(x > 0 && y < 0) {
        cout << 4 << endl;
    }
    if(x < 0 && y < 0) {
        cout << 3 << endl;
    }
}
