#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    long double mins = 0, seconds = 0;

    for(int i = 0; i < n; i++) {
        int m, s;
        cin >> m >> s;
        mins += m;
        seconds += s;
    }

    long double sl = (seconds / (mins * 60));

    if(sl <= 1) {
        cout << "measurement error" << endl;
    }
    else {
        cout.precision(9);
        cout << fixed << sl << endl;
    }
}
