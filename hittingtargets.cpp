#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

struct Rectangle {
    double x1;
    double y1;
    double x2;
    double y2;
};

struct Circle {
    double x;
    double y;
    double r;
};

int main() {
    int n;
    cin >> n;

    vector<Rectangle> rect;
    vector<Circle> circ;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if(s == "rectangle") {
            Rectangle r;
            cin >> r.x1 >> r.y1 >> r.x2 >> r.y2;
            rect.push_back(r);
        }
        else {
            Circle c;
            cin >> c.x >> c.y >> c.r;
            circ.push_back(c);
        }
    }

    cin >> n;

    for(int i = 0; i < n; i++) {
        int hits = 0;

        int x, y;
        cin >> x >> y;
        for(auto r : rect) {
            if(x <= r.x2 && x >= r.x1 && y <= r.y2 && y >= r.y1) {
                hits++;
            }
        }
        for(auto c : circ) {
            double d = sqrt(pow(abs(x-c.x),2) + pow(abs(y-c.y),2));
            if(d <= c.r) {
                hits++;
            }
        }
        cout << hits << endl;
    }
}
