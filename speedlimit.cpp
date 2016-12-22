#include <iostream>

using namespace std;

int main() {

    int n;
    while(true) {
        cin >> n;
        if(n == -1) {
            return 0;
        }
        int prev = 0;
        int miles = 0;
        for(int i = 0; i < n; i++) {
            int speed, curr;
            cin >> speed >> curr;
            miles += speed * (curr - prev);
            prev = curr;
        }
        cout << miles << " miles" << endl;
    }
}
