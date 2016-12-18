#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string num;
        cin >> num;
        cout << num.length() << endl;
    }
}
