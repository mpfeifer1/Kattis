#include <iostream>
#include <cmath>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    int i = 0, j = 0;
    for(auto c : s) {
        i *= 2;
        j *= 2;
        if(int(c-'0')&1) i++;
        if(int(c-'0')&2) j++;
    }

    cout << n << " " << i << " " << j << endl;
}
