#include <iostream>

using namespace std;

int getScore(int hi, int lo) {
    if(lo > hi) {
        swap(lo, hi);
    }
    if(hi == 2 && lo == 1) {
        return 100000;
    }
    if(hi == lo) {
        return hi * 100;
    }
    return hi * 10 + lo;
}

int main() {
    int a, b, c, d;
    while(cin >> a >> b >> c >> d && a != 0 && b != 0) {
        int score1 = getScore(a, b);
        int score2 = getScore(c, d);

        if(score1 == score2) {
            cout << "Tie." << endl;
            continue;
        }
        if(score1 > score2) {
            cout << "Player 1 wins." << endl;
            continue;
        }
        if(score1 < score2) {
            cout << "Player 2 wins." << endl;
            continue;
        }
    }
}
