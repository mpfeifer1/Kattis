#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int n;
    string s;

    cin >> n >> s;

    int maximum;

    // Adrian
    int a = 0;
    for(int i = 0; i < s.length(); i++) {
        if(i%3 == 0) {
            if(s[i] == 'A') {
                a++;
            }
        }
        if(i%3 == 1) {
            if(s[i] == 'B') {
                a++;
            }
        }
        if(i%3 == 2) {
            if(s[i] == 'C') {
                a++;
            }
        }
    }

    // Bruno
    int b = 0;
    for(int i = 0; i < s.length(); i++) {
        if(i%4 == 0) {
            if(s[i] == 'B') {
                b++;
            }
        }
        if(i%4 == 1) {
            if(s[i] == 'A') {
                b++;
            }
        }
        if(i%4 == 2) {
            if(s[i] == 'B') {
                b++;
            }
        }
        if(i%4 == 3) {
            if(s[i] == 'C') {
                b++;
            }
        }
    }

    // Gordon
    int g = 0;
    for(int i = 0; i < s.length(); i++) {
        if(i%6 == 0) {
            if(s[i] == 'C') {
                g++;
            }
        }
        if(i%6 == 1) {
            if(s[i] == 'C') {
                g++;
            }
        }
        if(i%6 == 2) {
            if(s[i] == 'A') {
                g++;
            }
        }
        if(i%6 == 3) {
            if(s[i] == 'A') {
                g++;
            }
        }
        if(i%6 == 4) {
            if(s[i] == 'B') {
                g++;
            }
        }
        if(i%6 == 5) {
            if(s[i] == 'B') {
                g++;
            }
        }
    }

    maximum = max(max(a, b), g);

    cout << maximum << endl;
    if(a == maximum) {
        cout << "Adrian" << endl;
    }
    if(b == maximum) {
        cout << "Bruno" << endl;
    }
    if(g == maximum) {
        cout << "Goran" << endl;
    }
}
