#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int different = 0;
    for(int i = 0; i < s.length(); i += 3) {
        if(s[i] != 'P') {
            different++;
        }
        if(s[i+1] != 'E') {
            different++;
        }
        if(s[i+2] != 'R') {
            different++;
        }
    }
    cout << different << endl;
}
