#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int inf = 1 << 30;
int INSIDE = 0;
int OUTSIDE = 1;
int ONEDGE = 2;
int COLINEAR = 0;
int CW = 1;
int CCW = 2;

typedef long double ld;

struct point {
    ld x, y;
    point(ld xloc, ld yloc) : x(xloc), y(yloc) {}
    point() {}
    point& operator= (const point& other) {
        x = other.x, y = other.y;
        return *this;
    }
    int operator == (const point& other) const {
        return (abs(other.x - x) < .00001 && abs(other.y - y) < .00001);
    }
    int operator != (const point& other) const {
        return !(abs(other.x - x) < .00001 && abs(other.y - y) < .00001);
    }
    bool operator< (const point& other) const {
        return (x < other.x ? true : (x == other.x && y < other.y));
    }
};

struct vect { ld i, j; };

struct segment {
    point p1, p2;
    segment(point a, point b) : p1(a), p2(b) {}
    segment() {}
};

long double crossProduct(point A, point B, point C) {
    vect AB, AC;
    AB.i = B.x - A.x;
    AB.j = B.y - A.y;
    AC.i = C.x - A.x;
    AC.j = C.y - A.y;
    return (AB.i * AC.j - AB.j * AC.i);
}

int orientation(point p, point q, point r) {
    int val = int(crossProduct(p, q, r));
    if(val == 0) {
        return COLINEAR;
    }
    return (val > 0) ? CW : CCW;
}

bool onSegment(point p, segment s) {
    return (p.x <= max(s.p1.x, s.p2.x) && p.x >= min(s.p1.x, s.p2.x) &&
            p.y <= max(s.p1.y, s.p2.y) && p.y >= min(s.p1.y, s.p2.y));
}

vector<point> intersect(segment s1, segment s2) {
    vector<point> res;
    point a = s1.p1, b = s1.p2, c = s2.p1, d = s2.p2;

    if(orientation(a, b, c) == 0 && orientation(a, b, d) == 0 &&
       orientation(c, d, a) == 0 && orientation(c, d, b) == 0) {
        point min_s1 = min(a, b), max_s1 = max(a, b);
        point min_s2 = min(c, d), max_s2 = max(c, d);

        if(min_s1 < min_s2) {
            if(max_s1 < min_s2) {
                return res;
            }
        }
        else if(min_s2 < min_s1 && max_s2 < min_s1) {
            return res;
        }

        point start = max(min_s1, min_s2), end = min(max_s1, max_s2);
        if(start == end) {
            res.push_back(start);
        }
        else {
            res.push_back(min(start, end));
            res.push_back(max(start, end));
        }
        return res;
    }
    double x1 = (b.x - a.x);
    double y1 = (b.y - a.y);
    double x2 = (d.x - c.x);
    double y2 = (d.y - c.y);
    double u1 = (-y1 * (a.x - c.x) + x1 * (a.y - c.y)) / (-x2 * y1 + x1 * y2);
    double u2 = (x2 * (a.y - c.y) - y2 * (a.x - c.x)) / (-x2 * y1 + x1 * y2);

    if(u1 >= 0 && u1 <= 1 && u2 >= 0 && u2 <= 1) {
        res.push_back(point((a.x + u2 * x1), (a.y + u2 * y1)));
    }
    return res;
}

int insidepoly(vector<point> poly, point p) {
    bool inside = false;
    point outside(inf, p.y);
    vector<point> intersection;

    for(unsigned int i = 0, j = poly.size()-1; i < poly.size(); i++, j = i-1) {
        if(p == poly[i] || p == poly[j]) {
            return ONEDGE;
        }
        if(orientation(p, poly[i], poly[j]) == COLINEAR && onSegment(p, segment(poly[i], poly[j]))) {
            return ONEDGE;
        }
        intersection = intersect(segment(p, outside), segment(poly[i], poly[j]));
        if(intersection.size() == 1) {
            if(poly[i] == intersection[0] && poly[j].y <= p.y) {
                continue;
            }
            if(poly[j] == intersection[0] && poly[i].y <= p.y) {
                continue;
            }
            inside = !inside;
        }
    }

    return inside ? INSIDE : OUTSIDE;
}

int main() {
    int n;
    while(cin >> n && n != 0) {
        vector<point> poly;
        for(int i = 0; i < n; i++) {
            point p;
            cin >> p.x >> p.y;
            poly.push_back(p);
        }

        cin >> n;
        for(int i = 0; i < n; i++) {
            point p;
            cin >> p.x >> p.y;

            int res = insidepoly(poly, p);
            if(res == 0) {
                cout << "in" << endl;
            }
            if(res == 1) {
                cout << "out" << endl;
            }
            if(res == 2) {
                cout << "on" << endl;
            }
        }

    }
}
