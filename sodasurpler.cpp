#include <iostream>

using namespace std;

int main() {
    int a, b, cost;
    cin >> a >> b >> cost;

    int starting = a + b;
    int total = 0;

    while(starting >= cost) {
        int drank = starting / cost;
        int left = starting % cost;
        total += drank;
        starting = left + drank;
    }

    cout << total << endl;
}
