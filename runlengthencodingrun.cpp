#include <bits/stdc++.h>

using namespace std;

void decode(string s) {
    for(int i = 0; i < s.size(); i += 2) {
        for(int j = 0; j < s[i+1]-'0'; j++) {
            cout << s[i];
        }
    }
    cout << endl;
}

void encode(string s) {
    char prev = s[0];
    int ct = 1;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] != prev) {
            cout << prev << ct;
            ct = 1;
            prev = s[i];
        }
        else {
            ct++;
        }
    }
    cout << prev << ct;
    cout << endl;
}

int main() {
    char c;
    cin >> c;
    string s;
    cin >> s;

    if(c == 'E') {
        encode(s);
    }
    else {
        decode(s);
    }
}
