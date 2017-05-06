#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double r;
    int m, c;
    cin >> r >> m >> c;

    cout.precision(17);

    double real = 0, sim = 0;
    while(!(r==0 && m==0 && c==0)) {
        real = M_PI * pow((double)r, 2);
        sim  = pow((double)r*2, 2) * ((double)c / m);

        cout << fixed << real << " " << fixed << sim << endl;

        cin >> r >> m >> c;
    }
}
