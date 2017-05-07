#include <iostream>
#include <string>

using namespace std;

int main() {
    string s, t;
    getline(cin,s);

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            i += 2;
        }
        t.push_back(s[i]);
    }

    cout << t << endl;
}
