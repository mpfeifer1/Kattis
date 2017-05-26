#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    unordered_set<string> dict;

    string s;
    while(cin >> s) {
        string temp = s;
        for(auto &c : temp) {
            c = tolower(c);
        }

        if(dict.count(temp) > 0) {
            cout << ". ";
        }
        else {
            dict.insert(temp);
            cout << s << " ";
        }

        if(cin.peek() == '\n') {
            cout << endl;
        }
    }
}
