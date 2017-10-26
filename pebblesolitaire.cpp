#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int solve(unordered_map<string, int>& memo, string s) {
    if(memo.count(s)) {
        return memo[s];
    }

    int dots = 0;
    for(auto i : s) {
        if(i == 'o') {
            dots++;
        }
    }

    for(int i = 0; i < s.size()-2; i++) {
        if(s[i] == 'o' && s[i+1] == 'o' && s[i+2] == '-') {
            s[i] = '-';
            s[i+1] = '-';
            s[i+2] = 'o';

            dots = min(dots, solve(memo, s));

            s[i] = 'o';
            s[i+1] = 'o';
            s[i+2] = '-';
        }
    }

    for(int i = 0; i < s.size()-2; i++) {
        if(s[i] == '-' && s[i+1] == 'o' && s[i+2] == 'o') {
            s[i] = 'o';
            s[i+1] = '-';
            s[i+2] = '-';

            dots = min(dots, solve(memo, s));

            s[i] = '-';
            s[i+1] = 'o';
            s[i+2] = 'o';
        }
    }

    memo[s] = dots;
    return dots;
}

int main() {
    int n;
    cin >> n;

    unordered_map<string, int> memo;

    while(n--) {
        string s;
        cin >> s;

        cout << solve(memo, s) << endl;
    }
}
