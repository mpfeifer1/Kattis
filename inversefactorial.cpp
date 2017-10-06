#include <iostream>
#include <cmath>

using namespace std;

int main() {
    string s;
    cin >> s;

    // Small factorials
    if(s.size() < 7) {
        int n = stoi(s);

        if(n <= 1) {
            cout << 1 << endl;
            return 0;
        }

        int divisor = 0;
        while(n != 1) {
            divisor++;
            n /= divisor;
        }

        cout << divisor << endl;
        return 0;
    }

    // Big factorials
    else {
        int i = 1;
        double ans = 1;

        while(true) {
            ans += log10(i);

            if(floor(ans) == s.size()) {
                cout << i << endl;
                break;
            }

            i++;
        }
    }
}
