#include <iostream>

using namespace std;

int main() {
    while(true) {
        int a, b;
        cin >> a >> b;
        if(a == 0 && b == 0) {
            return 0;
        }

        if(a + b == 13) {
            cout << "Never speak again." << endl;
            continue;
        }
        if(a == b) {
            cout << "Undecided." << endl;
            continue;
        }
        if(a > b) {
            cout << "To the convention." << endl;
            continue;
        }
        if(a < b) {
            cout << "Left beehind." << endl;
            continue;
        }
    }
}
