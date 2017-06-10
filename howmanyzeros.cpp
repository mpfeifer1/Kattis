#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

typedef unsigned long long ull;

using namespace std;

int getZeros(int num) {
    string s = to_string(num);
    int n = count(s.begin(), s.end(), '0');
    return n;
}

int main() {
    int i, j;

    ull big = 1 << 24;
    int* v = new int[big];

    cout << "HERE" << endl;

    v[0] = 1;
    for(int i = 1; i < big; i++) {
        v[i] = v[i-1] + getZeros(i);
    }

    cout << "HERE" << endl;

    while(cin >> i && cin >> j && i != -1 && j != -1) {
        int lo = v[i-1];
        int hi = v[j];
        if(i-1 < 0) {
            lo = 0;
        }
        cout << hi - lo << endl;
    }
}
