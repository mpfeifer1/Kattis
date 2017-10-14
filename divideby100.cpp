#include <iostream>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    while(s2.back() == '0' && s1.back() == '0') {
        s1.pop_back();
        s2.pop_back();
    }

    int len = s2.length();
    len--;
    len = s1.length() - len;

    if(len == s1.length()) {
        cout << s1 << endl;
        return 0;
    }


    if(s1.length() < s2.length()) {
        cout << "0.";
        for(int i = 0; i < s2.length()-s1.length()-1; i++) {
            cout << "0";
        }
        cout << s1 << endl;
        return 0;
    }

    for(int i = 0; i < len; i++) {
        cout << s1[i];
    }
    if(len == 0) {
        cout << "0";
    }
    cout << ".";
    for(int i = len; i < s1.length(); i++) {
        cout << s1[i];
    }
    cout << endl;
}

