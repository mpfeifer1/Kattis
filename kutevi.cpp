#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int num = 360;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        num = __gcd(num, t);
    }

    for(int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if(t % num == 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}
