#include <iostream>
#include <vector>

using namespace std;

int check(int i, int j, vector<vector<char>> v) {
    int handshakes = 0;

    if(v[i+1][j+1] == 'o') {
        handshakes++;
    }
    if(v[i+1][j] == 'o') {
        handshakes++;
    }
    if(v[i+1][j-1] == 'o') {
        handshakes++;
    }
    if(v[i][j+1] == 'o') {
        handshakes++;
    }
    if(v[i][j-1] == 'o') {
        handshakes++;
    }
    if(v[i-1][j+1] == 'o') {
        handshakes++;
    }
    if(v[i-1][j] == 'o') {
        handshakes++;
    }
    if(v[i-1][j-1] == 'o') {
        handshakes++;
    }

    return handshakes;
}

int main() {
    int r, s;
    cin >> r >> s;

    vector<vector<char>> v;
    v.resize(r+2, vector<char>(s+2, '.'));

    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= s; j++) {
            cin >> v[i][j];
        }
    }

    int handshakes = 0;

    // Add current handshakes
    for(int i = 0; i <= r; i++) {
        for(int j = 0; j <= s; j++) {
            if(v[i][j] == 'o' && v[i+1][j] == 'o') {
                handshakes++;
            }
            if(v[i][j] == 'o' && v[i][j+1] == 'o') {
                handshakes++;
            }
            if(v[i][j] == 'o' && v[i+1][j+1] == 'o') {
                handshakes++;
            }
            if(v[i][j] == 'o' && v[i-1][j+1] == 'o') {
                handshakes++;
            }
        }
    }


    int extra= 0;
    // Add new handshakes if more
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= s; j++) {
            if(v[i][j] == '.') {
                extra = max(extra, check(i, j, v));
            }
        }
    }

    cout << handshakes + extra << endl;
}
