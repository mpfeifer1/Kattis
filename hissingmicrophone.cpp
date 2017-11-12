#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    int i = 0;
    bool f = false;
    for(auto c : s) {
        if(c == 's') {
            i++;
            if(i == 2) {
                f = true;
            }
        }
        else {
            i = 0;
        }
    }

    if(f) {
        cout << "hiss" << endl;
    }
    else {
        cout << "no hiss" << endl;
    }
}
