#include <iostream>
#include <cmath>

using namespace std;

typedef long double ld;

ld dist(ld x1, ld y1, ld x2, ld y2) {
    return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}

int main() {
    int cases;
    cin >> cases;

    while(cases--) {
        ld x, y;
        cin >> x >> y;

        int n;
        cin >> n;

        bool works = false;
        for(int i = 0; i < n; i++) {
            ld x1, y1;
            cin >> x1 >> y1;
            if(dist(x, y, x1, y1) <= 8.000000001) {
                works = true;
            }
        }

        if(works) {
            cout << "light a candle" << endl;
        }
        else {
            cout << "curse the darkness" << endl;
        }
    }
}
