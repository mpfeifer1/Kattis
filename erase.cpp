#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string a;
    string b;

    int n;
    cin >> n;

    cin >> a >> b;

    bool success = true;

    if(n%2 == 1) {
        for(int i = 0; i < a.length(); i++) {
            if(a[i] == b[i]) {
                success = false;
            }
        }
    }
    else {
        for(int i = 0; i < a.length(); i++) {
            if(a[i] != b[i]) {
                success = false;
            }
        }
    }

    if(success) {
        cout << "Deletion succeeded" << endl;
    }
    else {
        cout << "Deletion failed" << endl;
    }
}
