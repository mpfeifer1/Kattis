#include <iostream>
#include <vector>

using namespace std;

struct pos {
    int x;
    int y;
};


bool inBoard(int x, int y) {
    return !(x > 8 || x < 1 || y > 8 || y < 1);
}

char c(int num) {
    return (char) num + 'A' - 1;
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        char a, b;

        cin >> a;
        cin >> y1;
        cin >> b;
        cin >> y2;

        x1 = a - 'A' + 1;
        x2 = b - 'A' + 1;

        pos p1 = {x1, y1};
        pos p2 = {x2, y2};

        vector<pos> v1;
        vector<pos> v2;

        // If they're the same
        if(p1.x == p2.x && p1.y == p2.y ) {
            cout << "0 " << a << " " << y1 << endl;
            continue;
        }

        // Get p1's possible moves
        for(int j = 0; j < 9; j++) {
            if(inBoard(p1.x+j, p1.y+j)) {
                v1.push_back({p1.x+j, p1.y+j});
            }
            if(inBoard(p1.x+j, p1.y-j)) {
                v1.push_back({p1.x+j, p1.y-j});
            }
            if(inBoard(p1.x-j, p1.y+j)) {
                v1.push_back({p1.x-j, p1.y+j});
            }
            if(inBoard(p1.x-j, p1.y-j)) {
                v1.push_back({p1.x-j, p1.y-j});
            }
        }

        // If p2 in p1's moves
        bool printed = false;
        for(int j = 0; j < v1.size(); j++) {
            if(v1[j].x == p2.x &&
               v1[j].y == p2.y) {
                cout << "1 " << c(p1.x) << " " << p1.y << " "
                             << c(p2.x) << " " << p2.y << endl;
                printed = true;
            }
        }
        if(printed) {
            continue;
        }

        // Get p2's possible moves
        for(int j = 0; j < 9; j++) {
            if(inBoard(p2.x+j, p2.y+j)) {
                v2.push_back({p2.x+j, p2.y+j});
            }
            if(inBoard(p2.x+j, p2.y-j)) {
                v2.push_back({p2.x+j, p2.y-j});
            }
            if(inBoard(p2.x-j, p2.y+j)) {
                v2.push_back({p2.x-j, p2.y+j});
            }
            if(inBoard(p2.x-j, p2.y-j)) {
                v2.push_back({p2.x-j, p2.y-j});
            }
        }

        // If p1 and p2 share moves
        int found = -1;
        for(int j = 0; j < v1.size(); j++) {
            for(int k = 0; k < v2.size(); k++) {
                if(v1[j].x == v2[k].x &&
                   v1[j].y == v2[k].y) {
                    found = j;
                }
            }
        }

        // If no shared moves
        if(found == -1) {
            cout << "Impossible" << endl;
            continue;
        }

        // If a shared move
        pos mid = v1[found];
        cout << "2 " << c(p1.x)  << " " << p1.y  << " "
                     << c(mid.x) << " " << mid.y << " "
                     << c(p2.x)  << " " << p2.y  << endl;
    }
}
