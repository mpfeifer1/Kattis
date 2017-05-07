#include <iostream>
#include <string>

using namespace std;

int main() {
    string s, t;
    cin >> s;
    t.push_back(s[0]);
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '-') {
            t.push_back(s[i+1]);
        }
    }
    cout << t << endl;
}
