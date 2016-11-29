#include <iostream>

using namespace std;

int main() {
    int j, k=0;
    cin >> j;
    for(int i = 0; i < j; i++) {
        int l;
        cin >> l;
        if(l < 0) {
            k++;
        }
    }
    cout << k << endl;
}
