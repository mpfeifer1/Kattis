#include <bits/stdc++.h>

using namespace std;

bool solve() {
    string s;
    cin >> s;

    reverse(s.begin(),s.end());

    int total = 0;

    for(int i = 0; i < s.size(); i++) {
        int d = s[i] - '0';
        if(i % 2 == 1) {
            d *= 2;
        }
        if(d >= 10) {
            d = (d%10) + (d/10);
        }
        total += d;
    }

    return total % 10 == 0;
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        if(solve()) {
            cout << "PASS" << endl;
        }
        else {
            cout << "FAIL" << endl;
        }
    }
}
