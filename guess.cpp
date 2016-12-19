#include <iostream>

using namespace std;

int main() {
    int min = 1;
    int max = 1001;
    int guess = 500;
    string result;

    int i = 0;
    while(i < 11) {
        guess = (max - min) / 2 + min;
        cout << guess << endl;
        cin >> result;

        if(result == "correct") {
            return 0;
        }
        if(result == "lower") {
            max = guess;
        }
        if(result == "higher") {
            min = guess;
        }
        i++;
    }
}
