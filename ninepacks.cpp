#include <iostream>
#include <vector>

using namespace std;

int main() {
    int inf = 1 << 29;
    int size;

    vector<int> h(100002, inf);
    vector<int> b(100002, inf);
    h[0] = 0;
    b[0] = 0;

    // Find all combinations of hotdogs
    cin >> size;
    for(int i = 0; i < size; i++) {
        int num;
        cin >> num;
        for(int j = h.size()-num-1; j >= 0; j--) {
            if(h[j] < h[j+num]) {
                h[j+num] = h[j]+1;
            }
        }
    }

    // Find all combinations of buns
    cin >> size;
    for(int i = 0; i < size; i++) {
        int num;
        cin >> num;
        for(int j = b.size()-num-1; j >= 0; j--) {
            if(b[j] < b[j+num]) {
                b[j+num] = b[j]+1;
            }
        }
    }

    // Get answer
    int best = inf;
    for(int i = 1; i < h.size(); i++) {
        if(h[i] + b[i] < best) {
            best = h[i] + b[i];
        }
    }

    /*
    for(int i = 0; i < 25; i++) {
        if(h[i] >= inf/2) {
            cout << "-1" << " ";
        }
        else {
            cout << h[i] << " ";
        }
    }
    cout << endl;
    for(int i = 0; i < 25; i++) {
        if(b[i] >= inf/2) {
            cout << "-1" << " ";
        }
        else {
            cout << b[i] << " ";
        }
    }
    cout << endl;
    */

    // Print result
    if(best >= inf/2) {
        cout << "impossible" << endl;
        return 0;
    }
    cout << best << endl;
}
