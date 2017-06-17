#include <iostream>

using namespace std;

int main() {
    int n = 1;
    int earth, mars;
    while(cin >> earth && cin >> mars) {
        cout << "Case " << n << ": ";

        int days = 0;
        while(earth != 0 || mars != 0) {
            days++;
            earth++;
            mars++;

            earth %= 365;
            mars %= 687;
        }

        cout << days << endl;

        n++;
    }
}
