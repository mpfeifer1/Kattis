#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if(b < a) {
        swap(a, b);
    }

    for(int i = a + 1; i < b + 2; i++) {
        cout << i << endl;
    }
}
