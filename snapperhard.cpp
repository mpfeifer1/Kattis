#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "Case #" << i+1 << ": ";

        int snappers;
        int snaps;
        cin >> snappers >> snaps;

        bool works = true;
        for(int j = 0; j < snappers; j++) {
            if(snaps % 2 == 0) {
                works = false;
            }
            snaps /= 2;
        }

        if(works) {
            cout << "ON" << endl;
        }
        else {
            cout << "OFF" << endl;
        }
    }
}
