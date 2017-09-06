#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int max = n-3;

    int total = 0;
    for(int i = 1; i <= max; i++) {
        for(int j = max - i + 1; j >= 1; j--) {
            total += j*i;
        }
    }

    cout << total << endl;
}
