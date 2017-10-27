#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    int k;
    cin >> n >> k;

    int total = 1;
    while(n > k) {
        total++;
        n -= ceil(double(n)/k);
    }

    total += n;

    cout << total << endl;
}
