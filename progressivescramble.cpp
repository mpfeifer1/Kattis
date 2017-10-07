#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int n;
    char c;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> c;
        cin.ignore();
        getline(cin, s);

        // Convert to int
        vector<int> str;
        for(auto i : s) {
            str.push_back(i - 'a' + 1);
            if(i == ' ') {
                str[str.size()-1] = 0;
            }
        }

        // Encrypt
        if(c == 'e') {
            for(int i = 1; i < str.size(); i++) {
                str[i] += str[i-1];
            }
            for(int i = 0; i < str.size(); i++) {
                str[i] %= 27;
            }
        }

        // Decrypt
        if(c == 'd') {
            for(int i = 1; i < str.size(); i++) {
                while(str[i] < str[i-1]) {
                    str[i] += 27;
                }
            }

            for(int i = str.size(); i > 0; i--) {
                str[i] -= str[i-1];
            }
        }

        // Convert to char
        for(int i = 0; i < str.size(); i++) {
            s[i] = str[i] + 'a' - 1;
            if(str[i] == 0) {
                s[i] = ' ';
            }
        }

        // Print answer
        cout << s << endl;
    }
}
