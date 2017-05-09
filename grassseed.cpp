#include <iostream>

using namespace std;

int main() {
    double cost;
    cin >> cost;

    int lawns;
    cin >> lawns;

    double totalArea;
    for(int i = 0; i < lawns; i++) {
        double l, w;
        cin >> l >> w;
        totalArea += l * w;
    }

    cout.precision(10);
    cout << fixed << totalArea * cost << endl;
}
