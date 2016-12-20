#include <iostream>
#include <cmath>

using namespace std;

int getRating(int n) {
    int total = 2;
    for(int i = 0; i < n; i++) {
        total += i;
    }
    return total;
}

int main() {
    int year;

    while(cin >> year) {
        if(year == 0) {
            return 0;
        }

        year -= 1940;
        int rating = getRating(year / 10);
        cout << rating << endl;
    }
}
