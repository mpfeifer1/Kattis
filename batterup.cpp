#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    double total = 0;
    double count = 0;

    while(n--) {
        double temp;
        cin >> temp;
        if(temp >= 0) {
            count++;
            total += temp;
        }
    }

    cout << fixed;
    cout.precision(9);

    cout << total/count << endl;
}
