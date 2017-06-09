#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long num = 2;

    while(n > 0) {
        num *= 2;
        num--;

        n--;
    }

    cout << num * num << endl;
}
