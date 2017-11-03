#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Get number of cases
    int cases;
    cin >> cases;

    while(cases--) {
        // Take in input
        int c;
        cin >> c;
        int beads;
        cin >> beads;

        // Reverse engineer board
        vector<int> board(1000, 0);
        int j = 0;
        while(beads--) {
            for(int i = 1; i <= board.size(); i++) {
                j = max(i, j);
                if(board[i] == 0) {
                    board[i] = i;
                    break;
                }
                else {
                    board[i]--;
                }
            }
        }

        // Print board
        cout << c << " " << j << endl;
        for(int i = 1; i <= j; i++) {
            cout << board[i] << " ";
            if(i % 10 == 0 && i != j) {
                cout << endl;
            }
        }
        cout << endl;
    }
}
