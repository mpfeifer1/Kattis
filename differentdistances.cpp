#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long double x1, x2, y1, y2, p;
    cout.precision(8);
    while(cin>>x1 && cin>>y1 && cin>>x2 && cin>>y2 && cin>>p) {
        long double x = pow(abs(x1-x2), p);
        long double y = pow(abs(y1-y2), p);
        cout << fixed << pow(x+y,(1/p)) << endl;
    }
}
