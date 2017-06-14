#include <iostream>
#include <cmath>

using namespace std;

void reduce(int& l, int& r) {
    for(int i = 2; i <= l && i <= r; i++) {
        if(l % i == 0 && r % i == 0) {
            l /= i;
            r /= i;

            // Set i to 1, it will be incremented to 2
            i = 1;
        }
    }
}

int main() {
    int n;
    cin >> n;
    n--;

    int big;
    cin >> big;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        int copy = big;

        reduce(copy, temp);

        cout << copy << "/" << temp << endl;
    }
}
