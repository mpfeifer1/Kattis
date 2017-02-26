#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        cout << ceil(num / 400.0) << endl;
    }
}
