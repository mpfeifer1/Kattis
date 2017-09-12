#include <iostream>
#include <string>

using namespace std;

bool isvowel(char c) {
    switch(c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'y':
            return true;
        default:
            return false;
    }
}

int count(string& s) {
    int doubles = 0;

    for(int i = 0; i < s.length() - 1; i++) {
        if(s[i] == s[i+1] && isvowel(s[i])) {
            doubles++;
        }
    }

    return doubles;
}

int main() {
    int n;
    while(cin >> n && n != 0) {
        string favorite = "none";
        int doubles = -1;

        for(int i = 0; i < n; i++) {
            string temp;
            cin >> temp;
            int d = count(temp);
            if(d > doubles) {
                doubles = d;
                favorite = temp;
            }
        }

        cout << favorite << endl;
    }
}
