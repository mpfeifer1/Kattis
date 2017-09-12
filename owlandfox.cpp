#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string temp;
    while(cin >> temp) {
        int i = temp.size()-1;
        while(temp[i] == '0') {
            i--;
        }
        temp[i]--;
        cout << stoi(temp) << endl;
    }
}
