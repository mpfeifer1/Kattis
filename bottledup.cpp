#include <iostream>

using namespace std;

int main() {
    int total, v1, v2;
    cin >> total >> v1 >> v2;

    bool swapped = false;
    if(v2 < v1) {
        swap(v1, v2);
        swapped = true;
    }

    bool printed = false;

    int v1_count = 0;
    while(total >= 0) {
        if(total % v2 == 0) {
            if(!swapped) {
                cout << v1_count << " " << total/v2 << endl;
            }
            else {
                cout << total/v2 << " " << v1_count << endl;
            }
            printed = true;
            break;
        }
        total -= v1;
        v1_count++;
    }

    if(!printed) {
        cout << "Impossible" << endl;
    }
}
