#include <iostream>
#include <cmath>

using namespace std;

int main() {
    string n;
    cin >> n;

    int s = n.length();
    int x = 0;
    int y = 0;

    for(int i = 0; i < s; i++) {
        if(n[i] == '0') {
        }
        if(n[i] == '1') {
            x += pow(2, s-i-1);
        }
        if(n[i] == '2') {
            y += pow(2, s-i-1);
        }
        if(n[i] == '3') {
            x += pow(2, s-i-1);
            y += pow(2, s-i-1);
        }
    }

    cout << s << " " << x << " " << y << endl;
}
