#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Setup
    vector<string> v = {"*"};
    int x = 0, y = 0;
    int startx = 0, starty = 0;
    string s;

    // For each command
    while(cin >> s) {
        // Go down
        if(s == "down") {
            y++;
            if(y >= v.size()) {
                string temp(v[0].size(), ' ');
                v.push_back(temp);
            }
        }

        // Go up
        if(s == "up") {
            y--;
            if(y < 0) {
                starty++;
                y++;
                string temp(v[0].size(), ' ');
                v.insert(v.begin(), temp);
            }
        }

        // Go left
        if(s == "left") {
            x--;
            if(x < 0) {
                startx++;
                x++;
                for(auto& i : v) {
                    i.insert(i.begin(), ' ');
                }
            }
        }

        // Go right
        if(s == "right") {
            x++;
            if(x >= v[0].size()) {
                for(auto& i : v) {
                    i.push_back(' ');
                }
            }
        }

        v[y][x] = '*';
    }

    // Get Start and End positions
    v[y][x] = 'E';
    v[starty][startx] = 'S';

    // Pad with '#'
    for(auto& i : v) {
        i.insert(i.begin(), '#');
        i.push_back('#');
    }
    string temp(v[0].size(), '#');
    v.insert(v.begin(), temp);
    v.push_back(temp);

    // Print answer
    for(auto str : v) {
        cout << str << endl;
    }
}
