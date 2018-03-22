#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    if(n <= 25) {
        cout << "a";
        cout << (char)('a'+n) << endl;
        return 0;
    }

    string s = "a";
    if(n % 25 == 0) {
        while(n >= 25) {
            n -= 25;
            if(s[s.size()-1] == 'a') {
                s.push_back('z');
            }
            else {
                s.push_back('a');
            }
        }
        cout << s << endl;
        return 0;
    }

    int rem = n % 25;
    bool secondrem = rem%2==1;

    s += 'n' + rem/2;

    while(n >= 25) {
        n -= 25;
        if(s[s.size()-1] == 'a') {
            s.push_back('z');
        }
        else {
            s.push_back('a');
        }
    }

    if(!secondrem) {
        if(s[s.size()-1] == 'a') {
            s[s.size()-1]++;
        }
        else {
            s[s.size()-1]--;
        }
    }

    cout << s << endl;
}
