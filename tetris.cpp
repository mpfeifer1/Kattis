#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> getpiecemap(int piece) {
    vector<vector<int>> piecemap;
    if(piece == 1) {
        piecemap.push_back({0});
        piecemap.push_back({0, 0, 0, 0});
    }
    if(piece == 2) {
        piecemap.push_back({0, 0});
    }
    if(piece == 3) {
        piecemap.push_back({0, 0, 1});
        piecemap.push_back({1, 0});
    }
    if(piece == 4) {
        piecemap.push_back({1, 0, 0});
        piecemap.push_back({0, 1});
    }
    if(piece == 5) {
        piecemap.push_back({1, 0, 1});
        piecemap.push_back({0, 0, 0});
        piecemap.push_back({1, 0});
        piecemap.push_back({0, 1});
    }
    if(piece == 6) {
        piecemap.push_back({2, 0});
        piecemap.push_back({0, 1, 1});
        piecemap.push_back({0, 0});
        piecemap.push_back({0, 0, 0});
    }
    if(piece == 7) {
        piecemap.push_back({0, 2});
        piecemap.push_back({1, 1, 0});
        piecemap.push_back({0, 0});
        piecemap.push_back({0, 0, 0});
    }

    return piecemap;
}

int getmatches(vector<int>& board, vector<int>& piece) {
    int total = 0;
    for(int i = 0; i < board.size() - (piece.size() - 1); i++) {
        bool works = true;
        int diff = board[i] - piece[0];
        for(int j = 1; j < piece.size(); j++) {
            if(diff != board[i+j] - piece[j]) {
                works = false;
            }
        }
        if(works) {
            total++;
        }
    }
    return total;
}

int main() {
    int boardsize, piece;
    cin >> boardsize >> piece;

    vector<int> board;
    for(int i = 0; i < boardsize; i++) {
        int temp;
        cin >> temp;
        board.push_back(temp);
    }

    vector<vector<int>> piecemap;
    piecemap = getpiecemap(piece);

    int total = 0;

    for(auto i : piecemap) {
        total += getmatches(board, i);
    }

    cout << total << endl;
}
