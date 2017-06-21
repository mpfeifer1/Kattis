#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    int i = 1;
    while(getline(cin, s) && s != "END") {
        cout << i << " ";
        i++;

        if(s.size() == 1) {
            cout << "EVEN" << endl;
            continue;
        }

        string pattern = "*";
        s.erase(s.begin());

        while(s[0] == '.') {
            pattern.push_back(s[0]);
            s.erase(s.begin());
        }

        while(s.find(pattern) == 0) {
            s.erase(0, pattern.length());
        }

        if(s.size() <= 1) {
            cout << "EVEN" << endl;
        }
        else {
            cout << "NOT EVEN" << endl;
        }
    }
}
