#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;
    while(cases--) {
        double d1, d2;
        cin >> d1 >> d2;

        if(d1 > d2) {
            swap(d1, d2);
        }

        double lo = 0;
        double hi = d1 / 2;

        while(hi - lo > .0000001) {
            double mid1 = (hi-lo) * (1.0/3) + lo;
            double mid2 = (hi-lo) * (2.0/3) + lo;
            double ans1 = mid1 * (d1-2*mid1) * (d2-2*mid1);
            double ans2 = mid2 * (d1-2*mid2) * (d2-2*mid2);

            if(ans1 > ans2) {
                hi = mid2;
            }
            else {
                lo = mid1;
            }
        }

        cout << fixed;
        cout.precision(9);
        cout << lo * (d1-2*lo) * (d2-2*lo) << endl;
    }
}
