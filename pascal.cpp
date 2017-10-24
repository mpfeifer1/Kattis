#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    if(n == 1) {
        cout << "0" << endl;
        return 0;
    }

    for(int i = 2; i < sqrt(n) + 1; i++) {
        if(n % i == 0) {
            cout << n - (n/i) << endl;
            return 0;
        }
    }

    cout << n-1 << endl;
}
