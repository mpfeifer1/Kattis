#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        long long r, e, c;
        cin >> r >> e >> c;

        if(e - c == r) {
            cout << "does not matter" << endl;
        }
        else if(e - c > r) {
            cout << "advertise" << endl;
        }
        else {
            cout << "do not advertise" << endl;
        }
    }
}
