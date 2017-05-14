#include <iostream>

using namespace std;

int positive(int n) {
    if(n < 0) {
        n = 0;
    }
    return n;
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int total = 0;
        int a, b;
        cin >> a;
        while(cin >> b && b != 0) {
            total += positive(b-(2*a));
            a = b;
        }
        cout << total << endl;
    }
}
