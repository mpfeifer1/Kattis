#include <iostream>

using namespace std;

int main() {
    int scores[5][4];

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> scores[i][j];
        }
    }

    for(int i = 0; i < 5; i++) {
        for(int j = 1; j < 4; j++) {
            scores[i][0] += scores[i][j];
        }
    }


    int max = -1;
    int loc = -1;
    for(int i = 0; i < 5; i++) {
        if(scores[i][0] > max) {
            max = scores[i][0];
            loc = i;
        }
    }
    cout << loc+1 << " " << max << endl;
}
