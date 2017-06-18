#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int n;
    while(cin >> n) {
        cin.ignore();
        string s;
        getline(cin, s);

        string temp = "";
        string backslashes;
        backslashes.resize(pow(2, n) - 1, '\\');

        for(auto c : s) {
            if(('!' <= c && c <= '*') || ('[' <= c && c <= ']')) {
                temp += backslashes;
            }
            temp.push_back(c);
        }

        cout << temp << endl;
    }
}
