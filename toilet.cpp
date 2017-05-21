#include <iostream>
#include <string>

using namespace std;

int up(string& s) {
    int n = 0;

    char pos = s[0];

    for(int i = 1; i < s.length(); i++) {
        if(pos != s[i]) {
            pos = s[i];
            n++;
        }
        if(pos != 'U') {
            pos = 'U';
            n++;
        }
    }

    return n;
}

int down(string& s) {
    int n = 0;

    char pos = s[0];

    for(int i = 1; i < s.length(); i++) {
        if(pos != s[i]) {
            pos = s[i];
            n++;
        }
        if(pos != 'D') {
            pos = 'D';
            n++;
        }
    }

    return n;
}

int last(string& s) {
    int n = 0;
    char old = s[0];
    for(int i = 1; i < s.length(); i++) {
        if(s[i] != old) {
            n++;
        }
        old = s[i];
    }
    return n;
}

int main() {
    string s;
    cin >> s;

    cout << up(s) << endl << down(s) << endl << last(s) << endl;
}
