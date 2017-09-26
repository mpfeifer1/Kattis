#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool beats(char me, char they) {
    // Doesn't beat if same
    if(me == they) {
        return false;
    }

    // Return true if they win
    if(me == 'R' && they == 'P') {
        return true;
    }
    if(me == 'P' && they == 'S') {
        return true;
    }
    if(me == 'S' && they == 'R') {
        return true;
    }

    // Otherwise return false
    return false;
}

char fight(vector<string>& v, int i, int j, int r, int c) {
    // Find this type
    char me = v[i][j];

    // Grab all the competitors
    vector<char> competitors;
    if(i-1 >= 0) {
        competitors.push_back(v[i-1][j]);
    }
    if(i+1 < r) {
        competitors.push_back(v[i+1][j]);
    }
    if(j-1 >= 0) {
        competitors.push_back(v[i][j-1]);
    }
    if(j+1 < c) {
        competitors.push_back(v[i][j+1]);
    }

    // If anyone beats this, they are the winner
    char winner = me;
    for(auto i : competitors) {
        if(beats(me, i)) {
            winner = i;
        }
    }

    // Return the winner
    return winner;
}

vector<string> advance(vector<string> v, int r, int c) {
    vector<string> out;
    out = v;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            out[i][j] = fight(v, i, j, r, c);
        }
    }

    return out;
}

int main() {
    int cases;
    cin >> cases;

    bool first = true;
    for(int i = 0; i < cases; i++) {
        // Print a line if not first time
        if(first) {
            first = false;
        }
        else {
            cout << endl;
        }

        // Get input
        int r, c, t;
        cin >> r >> c >> t;

        // Get grid
        vector<string> v;
        for(int j = 0; j < r; j++) {
            string s;
            cin >> s;
            v.push_back(s);
        }

        // Advance grid
        for(int j = 0; j < t; j++) {
            v = advance(v, r, c);
        }

        // Print grid
        for(auto i : v) {
            cout << i << endl;
        }
    }
}
