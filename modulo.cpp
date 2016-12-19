#include <iostream>

using namespace std;

int main() {
    bool mod[42];
    for(int i = 0; i < 42; i++) {
        mod[i] = false;
    }

    for(int i = 0; i < 10; i++) {
        int temp;
        cin >> temp;
        mod[temp%42] = true;
    }

    int trues = 0;

    for(int i = 0; i < 42; i++) {
        if(mod[i]) {
            trues++;
        }
    }

    cout << trues << endl;
}
