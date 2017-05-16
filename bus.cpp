#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        double ans = 0;
        for(int i = 0; i < temp; i++) {
            ans += .5;
            ans *= 2;
        }

        cout << (long long)ans << endl;
    }
}
