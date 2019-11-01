#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, a, b, c;
    cin >> m >> a >> b >> c;
    
    a += b;
    a += c;
    
    if(2*m - a >= 0) {
        cout << "possible" << endl;
    }
    else {
        cout << "impossible" << endl;
    }
}

