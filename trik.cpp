#include <iostream>
#include <string>

using namespace std;

int main() {
    bool ball[3] = {true, false, false};
    string moves;
    cin >> moves;
    for(int i = 0; i < moves.size(); i++) {
        if(moves[i] == 'A') {
            swap(ball[0], ball[1]);
        }
        if(moves[i] == 'B') {
            swap(ball[1], ball[2]);
        }
        if(moves[i] == 'C') {
            swap(ball[0], ball[2]);
        }
    }
    if(ball[0]) {
        cout << "1" << endl;
    }
    if(ball[1]) {
        cout << "2" << endl;
    }
    if(ball[2]) {
        cout << "3" << endl;
    }
}
