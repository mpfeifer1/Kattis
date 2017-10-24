#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    ll m=0, t=0;
    while(n--) {
        ll temp;
        cin >> temp;
        m = max(temp, m);
        t += temp;
    }

    cout << max(t, m*2) << endl;
}
