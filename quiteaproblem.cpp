#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;

    while(getline(cin, s)) {
        for(auto& x : s) {
            x = tolower(x);
        }
        if(s.find("problem") != string::npos) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }
}
