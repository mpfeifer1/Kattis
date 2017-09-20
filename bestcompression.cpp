#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long n, b;
    cin >> n >> b;

    if(n <= pow(2,(b+1)) - 1) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }
}
