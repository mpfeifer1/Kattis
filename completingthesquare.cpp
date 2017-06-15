#include <iostream>
#include <cmath>

using namespace std;

typedef pair<double, double> point;

double getdistance(point p1, point p2) {
    double xdist = p1.first - p2.first;
    double ydist = p1.second - p2.second;

    double dist = sqrt(pow(xdist, 2) + pow(ydist, 2));

    return dist;
}

point midpoint(point p1, point p2) {
    point temp;
    temp.first = (p1.first + p2.first) / 2;
    temp.second = (p1.second + p2.second) / 2;
    return temp;
}

point getnextpoint(point edge, point center) {
    double xdiff = center.first - edge.first;
    double ydiff = center.second - edge.second;

    point temp = {center.first + xdiff, center.second + ydiff};
    return temp;
}

void printpoint(point p) {
    cout << p.first << " " << p.second << endl;
}

int main() {
    int x1, y1;
    int x2, y2;
    int x3, y3;

    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

    point p1, p2, p3;
    p1 = {x1, y1};
    p2 = {x2, y2};
    p3 = {x3, y3};

    double d1, d2, d3;
    d1 = getdistance(p1, p2);
    d2 = getdistance(p2, p3);
    d3 = getdistance(p3, p1);

    double m = max(max(d1, d2), d3);

    point center;
    point ans;

    if(m == d1) {
        center = midpoint(p1, p2);
        ans = getnextpoint(p3, center);
    }
    if(m == d2) {
        center = midpoint(p3, p2);
        ans = getnextpoint(p1, center);
    }
    if(m == d3) {
        center = midpoint(p1, p3);
        ans = getnextpoint(p2, center);
    }

    printpoint(ans);
}
