#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int w, h;
    int count = 1;
    while(cin >> w && cin >> h && !(w == 0 || h == 0)) {
        // Print header
        cout << "HOUSE " << count << endl;
        count++;

        // Take in house
        vector<string> house;
        for(int i = 0; i < h; i++) {
            string s;
            cin >> s;
            house.push_back(s);
        }

        // Find start
        int startx, starty;
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(house[i][j] == '*') {
                    startx = j;
                    starty = i;
                }
            }
        }

        // Find starting direction
        char dir = ' ';
        if(startx == 0) {
            dir = 'r';
        }
        if(startx == w-1) {
            dir = 'l';
        }
        if(starty == 0) {
            dir = 'd';
        }
        if(starty == h-1) {
            dir = 'u';
        }

        // Simulate
        int currx = startx;
        int curry = starty;
        while(house[curry][currx] != 'x') {
            // Move
            if(dir == 'r') {
                currx++;
            }
            if(dir == 'l') {
                currx--;
            }
            if(dir == 'u') {
                curry--;
            }
            if(dir == 'd') {
                curry++;
            }

            // Check if mirror 1
            if(house[curry][currx] == '/') {
                if(dir == 'r') {
                    dir = 'u';
                }
                else if(dir == 'l') {
                    dir = 'd';
                }
                else if(dir == 'u') {
                    dir = 'r';
                }
                else if(dir == 'd') {
                    dir = 'l';
                }
            }

            // Check if mirror 2
            if(house[curry][currx] == '\\') {
                if(dir == 'r') {
                    dir = 'd';
                }
                else if(dir == 'd') {
                    dir = 'r';
                }
                else if(dir == 'l') {
                    dir = 'u';
                }
                else if(dir == 'u') {
                    dir = 'l';
                }
            }
        }

        // Mark last spot
        house[curry][currx] = '&';

        // Print house
        for(auto i : house) {
            cout << i << endl;
        }
    }
}
