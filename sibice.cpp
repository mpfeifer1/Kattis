#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    double x, y;
    cin >> x >> y;

    double length = sqrt((x*x)+(y*y));

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if(temp <= length) {
            cout << "DA" << endl;
        }
        else {
            cout << "NE" << endl;
        }
    }
}
