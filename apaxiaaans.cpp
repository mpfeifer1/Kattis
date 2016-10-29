#include <iostream>
#include <string>

using namespace std;

int main() {
    string name;
    cin >> name;
    if(name.length() == 1) {
        cout << name << endl;
        return 0;
    }
    for(int i = 0; i < name.length(); i++) {
        if(name[i] == name[i+1]) {
            name.erase(i, 1);
            i--;
        }
    }
    cout << name << endl;
}
