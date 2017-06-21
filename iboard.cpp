#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    while(getline(cin, s)) {
        int ones = 0;
        int zeroes = 0;

        for(auto c : s) {
            for(int i = 0; i < 7; i++) {
                if(c % 2 == 0) {
                    zeroes++;
                }
                else {
                    ones++;
                }
                c >>= 1;
            }
        }

        if(ones % 2 == 1 || zeroes % 2 == 1) {
            cout << "trapped" << endl;
        }
        else {
            cout << "free" << endl;
        }
    }
}
