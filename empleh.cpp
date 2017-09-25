#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void fill(vector<string>& v, string& s) {
    // If no pieces, quit
    if(s == "") {
        return;
    }

    // Process all the pieces
    v.push_back("");
    reverse(s.begin(), s.end());
    while(!s.empty()) {
        if(s.back() == ',') {
            v.push_back("");
        }
        else {
            v[v.size()-1].push_back(s.back());
        }
        s.pop_back();
    }

}

void place(vector<string>& board, string piece, bool color) {
    char letter = 'p';

    if(piece.size() == 3) {
        letter = piece[0];
        piece.erase(0, 1);
    }

    if(color) {
        letter = toupper(letter);
    }
    else {
        letter = tolower(letter);
    }

    int x = piece[0] - 'a';
    int y = 7 - (piece[1] - '1');

    x *= 4;
    y *= 2;

    x += 2;
    y += 1;

    board[y][x] = letter;
}

int main() {
    // Take in the data
    string w, b;
    getline(cin, w);
    getline(cin, b);

    // Make it usable
    w = w.substr(7);
    b = b.substr(7);
    vector<string> whites;
    vector<string> blacks;
    fill(whites, w);
    fill(blacks, b);

    // Build the board
    string border = "+---+---+---+---+---+---+---+---+";
    string space1 = "|...|:::|...|:::|...|:::|...|:::|";
    string space2 = "|:::|...|:::|...|:::|...|:::|...|";

    vector<string> board;
    board.push_back(border);
    board.push_back(space1);
    board.push_back(border);
    board.push_back(space2);
    board.push_back(border);
    board.push_back(space1);
    board.push_back(border);
    board.push_back(space2);
    board.push_back(border);
    board.push_back(space1);
    board.push_back(border);
    board.push_back(space2);
    board.push_back(border);
    board.push_back(space1);
    board.push_back(border);
    board.push_back(space2);
    board.push_back(border);

    for(auto i : whites) {
        place(board, i, true);
    }
    for(auto i : blacks) {
        place(board, i, false);
    }

    for(auto i : board) {
        cout << i << endl;
    }
}
