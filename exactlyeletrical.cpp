#include <iostream>

using namespace std;

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int gas;
    cin >> gas;

    int dist = abs(y2-y1) + abs(x2-x1);
    gas -= dist;

    if(gas < 0) {
        cout << "N" << endl;
        return 0;
    }

    if(gas % 2 == 0) {
        cout << "Y" << endl;
    }
    else {
        cout << "N" << endl;
    }
}
