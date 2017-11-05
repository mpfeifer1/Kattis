#include <unordered_map>
#include <iostream>

using namespace std;

int main() {
    unordered_map<string, int> s;

    string temp;
    while(cin >> temp) {
        s[temp]++;
        if(s[temp] > 1) {
            cout << "no" << endl;
            return 0;
        }
    }

    cout << "yes" << endl;
}
