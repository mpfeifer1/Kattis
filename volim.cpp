#include <iostream>

using namespace std;

int main() {
    int player;
    cin >> player;

    int time = 0;
    bool exploded = false;

    int n;
    cin >> n;

    do {
        int t;
        char c;

        cin >> t;
        cin >> c;

        time += t;

        if(time >= 210) {
            exploded = true;
        }
        else if(c == 'T') {
            player++;
        }
    } while(!exploded);

    player--;
    player %= 8;
    player++;
    cout << player << endl;
}
