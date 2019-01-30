#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;

int main() {
    ld d;
    cin >> d;

    d *= 1000 * 5280;
    d /= 4854;

    d += .50001;

    cout << ll(d) << endl;
}
