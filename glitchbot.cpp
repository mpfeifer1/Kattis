#include <iostream>
#include <vector>
#include <string>

using namespace std;

string other(string original) {
    if(original == "Left") {
        return "Right";
    }
    if(original == "Right") {
        return "Forward";
    }
    else {
        return "Left";
    }
}

string other2(string original) {
    if(original == "Left") {
        return "Forward";
    }
    if(original == "Right") {
        return "Left";
    }
    else {
        return "Right";
    }
}

int turn(int dir, string direction) {
    if(direction == "Left") {
        dir--;
    }
    if(direction == "Right") {
        dir++;
    }

    if(dir < 0) {
        dir += 4;
    }

    if(dir > 3) {
        dir -= 4;
    }

    return dir;
}

void move(int& x, int& y, int& dir, string direction) {
    if(direction == "Forward") {
        if(dir == 0) {
            y++;
        }
        if(dir == 1) {
            x++;
        }
        if(dir == 2) {
            y--;
        }
        if(dir == 3) {
            x--;
        }
    }
    else {
        dir = turn(dir, direction);
    }
}

bool process(int x, int y, vector<string>& moves) {
    int currX = 0;
    int currY = 0;
    int dir = 0;

    for(auto i : moves) {
        move(currX, currY, dir, i);
    }

    if(currX == x && currY == y) {
        return true;
    }

    return false;
}

int main() {
    int endX, endY;
    cin >> endX >> endY;

    int n;
    cin >> n;

    vector<string> moves;
    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        moves.push_back(temp);
    }

    for(int i = 0; i < moves.size(); i++) {
        string original = moves[i];
        moves[i] = other(original);
        if(process(endX, endY, moves)) {
            cout << i+1 << " " << moves[i] << endl;
            return 0;
        }
        moves[i] = other2(original);
        if(process(endX, endY, moves)) {
            cout << i+1 << " " << moves[i] << endl;
            return 0;
        }
        moves[i] = original;
    }
}
