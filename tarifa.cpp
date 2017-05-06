#include <iostream>

using namespace std;

int main() {
    int megabytes = 0;
    int months = 0;

    cin >> megabytes >> months;

    int used = 0;
    for(int i = 0; i < months; i++) {
        int temp;
        cin >> temp;
        used += temp;
    }

    cout << megabytes * (months+1) - used << endl;
}
