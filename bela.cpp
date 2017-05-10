#include <iostream>

using namespace std;

int getVal(char c) {
    switch(c) {
        case 'A':
            return 11;
        case 'K':
            return 4;
        case 'Q':
            return 3;
        case 'J':
            return 2;
        case 'T':
            return 10;
    }
    return 0;
}

int getValTrump(char c) {
    switch(c) {
        case 'A':
            return 11;
        case 'K':
            return 4;
        case 'Q':
            return 3;
        case 'J':
            return 20;
        case 'T':
            return 10;
        case '9':
            return 14;
    }
    return 0;
}

int main() {
    int hands;
    char trump;

    cin >> hands;
    cin >> trump;

    char num;
    char suit;

    int sum = 0;

    while(cin >> num && cin >> suit) {
        if(suit == trump) {
            sum += getValTrump(num);
        }
        else {
            sum += getVal(num);
        }
    }

    cout << sum << endl;
}
