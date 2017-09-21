#include <iostream>
#include <string>

using namespace std;

int total = 0;

void solve(int loc, int target, string& s, string& match) {
    if(target == match.length()) {
        total++;
        return;
    }

    for(int i = loc; i < s.length(); i++) {
        if(match[target] == s[i]) {
            solve(i+1, target+1, s, match);
        }
    }

    return;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    for(int i = 1; i <= n; i++) {
        // Read input
        string s;
        getline(cin, s);

        // Solve the problem
        string match = "welcome to code jam";
        solve(0, 0, s, match);

        // Make exactly 4 characters
        string t = to_string(total);
        while(t.length() > 4) {
            t.erase(0, 1);
        }
        while(t.length() < 4) {
            t.insert(0, 1, '0');
        }

        cout << "Case #" << i << ": " << t << endl;
        total = 0;
    }
}
