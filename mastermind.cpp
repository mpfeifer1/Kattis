#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string code, guess;
    cin >> code >> guess;

    string codeleft, guessleft;

    int r = 0, s = 0;
    for(int i = 0; i < n; i++) {
        if(code[i] == guess[i]) {
            r++;
        }
        else {
            codeleft.push_back(code[i]);
            guessleft.push_back(guess[i]);
        }
    }

    while(!codeleft.empty()) {
        int index = guessleft.find(codeleft[0]);
        if(index >= 0) {
            s++;
            guessleft.erase(guessleft.begin()+index);
        }
        codeleft.erase(codeleft.begin());
    }

    cout << r << " " << s << endl;
}
