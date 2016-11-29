#include <iostream>

using namespace std;

int main() {
    int cases;
    cin >> cases;

    int num;
    for(int i = 0; i < cases; i++) {
        cin >> num;
        if(num % 2 == 0) {
            cout << num << " is even" << endl;
        }
        else {
            cout << num << " is odd" << endl;
        }
    }
}
