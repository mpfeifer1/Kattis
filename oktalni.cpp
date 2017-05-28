#include <iostream>
#include <string>

using namespace std;

int conv(string s, int index) {
    int n = 0;
    if(s[index] == '1') {
        n += 4;
    }
    if(s[index+1] == '1') {
        n += 2;
    }
    if(s[index+2] == '1') {
        n += 1;
    }
    return n;
}

int main() {
    string s;
    cin >> s;

    while(s.length() % 3 != 0) {
        s.insert(s.begin(),'0');
    }

    for(int i = 0; i < s.length(); i+=3) {
        cout << conv(s, i);
    }

    cout << endl;
}
