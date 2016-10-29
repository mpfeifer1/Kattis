#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int size;
    while(cin >> size) {
        if(size < 1) {
            cout << 0 << endl;
        }
        else if(size == 1) {
            cout << 1 << endl;
        }
        else {
            cout << 2 * size - 2 << endl;
        }
    }
}
