#include <iostream>
#include <string>

using namespace std;


int main() {
    int n;
    cin >> n;

    int a = 1, b = 0;

    for(int i = 0; i < n; i++) {
        int tempa, tempb;
        tempa = b;
        tempb = a + b;
        a = tempa;
        b = tempb;
    }
    cout << a << " " << b << endl;
}
