#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void rotate(char& c) {
    c++;
    if(c == 'Z' + 1) {
        c = '_';
    }
    if(c == '_' + 1) {
        c = '.';
    }
    if(c == '.' + 1) {
        c = 'A';
    }
}

int main() {
    int rotation;
    string s;

    while(cin >> rotation && cin >> s) {
        reverse(s.begin(), s.end());
        for(int j = 0; j < s.length(); j++) {
            for(int i = 0; i < rotation; i++) {
                rotate(s[j]);
            }
        }
        cout << s << endl;
    }
}
