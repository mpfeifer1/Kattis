#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;
typedef long double ld;

struct point {
    ld x, y;
    point(ld xloc, ld yloc) : x(xloc), y(yloc){}
    point(){}
    point& operator= (const point& other) {
        x = other.x, y = other.y;
        return *this;
    }
    int operator == (const point& other) const {
        return (other.x == x && other.y == y);
    }
    int operator != (const point& other) const {
        return !(other.x == x && other.y == y);
    }
    bool operator< (const point& other) const {
        return (x < other.x ? true : (x == other.x && y < other.y));
    }
};

struct vect {ld i, j;};

struct segment {
    point p1, p2;
    segment(point a, point b) : p1(a), p2(b){}
    segment(){}
};

#define COLINEAR 0
#define CW 1
#define CCW 2

ld crossProduct(point A, point B, point C) {
    vect AB, AC;
    AB.i = B.x - A.x;
    AB.j = B.y - A.y;
    AC.i = C.x - A.x;
    AC.j = C.y - A.y;
    return (AB.i * AC.j - AB.j * AC.i);
}

int orientation(point p, point q, point r) {
    int val = (int)crossProduct(p, q, r);
    if(val == 0) {
        return COLINEAR;
    }
    return (val > 0) ? CW : CCW;
}

bool straddle(segment s1, segment s2) {
    ld cross1 = crossProduct(s1.p1, s1.p2, s2.p1);
    ld cross2 = crossProduct(s1.p1, s1.p2, s2.p2);

    if((cross1 > 0 && cross2 > 0) || (cross1 < 0 && cross2 < 0)) {
        return false;
    }
    if(cross1 == 0 && cross2 == 0 && orientation(s1.p2, s2.p1, s2.p2) != COLINEAR) {
        return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<segment> lines;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        point p1, p2;
        cin >> p1.x >> p1.y >> p2.x >> p2.y;
        segment s(p1, p2);
        lines.push_back(s);
    }

    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        point p1, p2;
        cin >> p1.x >> p1.y >> p2.x >> p2.y;
        segment s(p1, p2);

        int total = 0;
        for(int i = 0; i < n; i++) {
            if(straddle(lines[i], s)) {
                total++;
            }
        }

        if(total % 2 == 0) {
            cout << "same" << endl;
        }
        else {
            cout << "different" << endl;
        }
    }
}

