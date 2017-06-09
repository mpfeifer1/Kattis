#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        if(a < b) {
            cout << "impossible" << endl;
            continue;
        }

        if((a + b) % 2 == 1) {
            cout << "impossible" << endl;
            continue;
        }

        int hi = (a + b) / 2;
        int lo = a - hi;

        if(lo > hi) {
            swap(lo, hi);
        }

        cout << hi << " " << lo << endl;
    }
}
