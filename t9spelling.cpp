#include <bits/stdc++.h>

using namespace std;

int main() {
    int times;
    cin >> times;
    vector<string> chars =
        {"2","22","222",
         "3","33","333",
         "4","44","444",
         "5","55","555",
         "6","66","666",
         "7","77","777","7777",
         "8","88","888",
         "9","99","999","9999",
         "0"};
    cin.ignore();
    for(int i = 0; i < times; i++) {
        string line;
        getline(cin,line);
        cout << "Case #" << i+1 << ": ";
        int prev = 0;
        for(auto c : line) {
            if(c != ' ') {
                if(chars[prev][0] == chars[c-'a'][0]) {
                    cout << " ";
                }
                cout << chars[c-'a'];
                prev = c-'a';
            }
            else if(c == ' ' && prev == 26) {
                cout << " 0";
            }
            else {
                cout << "0";
                prev = 26;
            }
        }
        cout << endl;
    }
}
