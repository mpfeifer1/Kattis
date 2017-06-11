#include <iostream>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    a += b;

    if((a / n) % 2 == 0) {
        cout << "paul" << endl;
        return 0;
    }

    cout << "opponent" << endl;
}
