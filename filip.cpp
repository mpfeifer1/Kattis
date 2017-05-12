#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;
    string b;

    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    if(a < b) {
        cout << b << endl;
    }
    else {
        cout << a << endl;
    }
}
