#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int w = 0;
    int b = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'W') {
            w++;
        }
        if(s[i] == 'B') {
            b++;
        }
    }
    if(w == b) {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }
}
