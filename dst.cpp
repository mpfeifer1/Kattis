#include <iostream>

using namespace std;

void rollforward(int d, int& h, int& m) {
    for(int i = 0; i < d; i++) {
        m++;
        if(m == 60) {
            m = 0;
            h++;
        }
        if(h == 24) {
            h = 0;
        }
    }
}

void rollbackward(int d, int& h, int& m) {
    for(int i = 0; i < d; i++) {
        m--;
        if(m == -1) {
            m = 59;
            h--;
        }
        if(h == -1) {
            h = 23;
        }
    }
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        char c;
        int d, h, m;
        cin >> c >> d >> h >> m;

        if(c == 'F') {
            rollforward(d, h, m);
        }
        else {
            rollbackward(d, h, m);
        }

        cout << h << " " << m << endl;
    }
}
