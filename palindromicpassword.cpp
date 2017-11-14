#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool ispalindrome(int i) {
    string s = to_string(i);
    while(s.length() < 6) {
        s = "0" + s;
    }

    return ((s[0] == s[5]) && (s[1] == s[4]) && (s[2] == s[3]));
}

int solve(vector<bool>& memo, int i) {
    int j, k;
    for(j = i; j >= 0; j--) {
        if(memo[j]) {
            break;
        }
    }
    for(k = i; k <= 999999; k++) {
        if(memo[k]) {
            break;
        }
    }

    int diff1 = abs(j - i);
    int diff2 = abs(k - i);
    if(diff1 <= diff2) {
        return j;
    }
    else {
        return k;
    }
}

void build(vector<bool>& memo) {
    for(int i = 0; i <= 1000000; i++) {
        if(ispalindrome(i)) {
            memo[i] = true;
        }
    }
}

int main() {
    int cases;
    cin >> cases;

    vector<bool> memo(1000002, false);
    build(memo);

    while(cases--) {
        int s;
        cin >> s;

        cout << solve(memo, s) << endl;
    }
}
