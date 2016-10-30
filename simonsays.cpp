#include <iostream>
#include <string>

using namespace std;

int main() {
    int times;
    cin >> times;
    cin.ignore();
    for(int i = 0; i < times; i++) {
        string s;
        getline(cin, s);
        if(s.find("Simon says") == 0) {
            s.erase(0,11);
            cout << s << endl;
        }
    }
}
