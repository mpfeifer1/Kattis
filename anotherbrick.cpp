#include <iostream>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    int n;
    cin >> n;

    int laid = 0;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        laid += temp;

        if(laid > w) {
            cout << "NO" << endl;
            return 0;
        }
        if(laid == w) {
            laid = 0;
            h--;
        }
        if(h == 0) {
            break;
        }
    }

    if(h == 0) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
