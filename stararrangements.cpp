#include <bits/stdc++.h>

using namespace std;

bool solve(int n, int a, int b) {
    if(n % (a+b) == 0 || n % (a + b) == a) {
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    cout << n << ":" << endl;

    for(int i = 2; i <= (n+1)/2; i++) {
        for(int j = -1; j <= 0; j++) {
            if(solve(n, i, i+j)) {
                cout << i << "," << i+j << endl;
            }
        }
    }
}
