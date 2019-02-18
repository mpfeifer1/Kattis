#include <bits/stdc++.h>

using namespace std;
typedef long double ld;

//Constant values to be returned
constexpr int Colinear = -1, NoIntersect = 0, Intersect = 1;
constexpr int CW = 2, CCW = 3;
constexpr int Inside = 4, Outside = 5, OnEdge = 6;

//Epsilon for all double comparisons
const ld EPSILON = 0.000001;
const ld eps = EPSILON;

struct point
{
    long double x, y;

    point(long double x_=0, long double y_=0) : x(x_), y(y_){}

    // Only < operator is unusual behavior
    bool operator <(const point& other) const
    {
        return (x < other.x ? true : (x == other.x && y < other.y));
    }

    bool operator == (const point& other) const
    {
        return abs(other.x - x) < EPSILON && abs(other.y - y) < EPSILON;
    }

    //Add other operators as needed
    point operator + (const point& other) const
    {
        return point(this->x + other.x, this->y + other.y);
    }

    point operator - (const point& other) const
    {
        return point(this->x - other.x, this->y - other.y);
    }

    point operator * (long double other) const
    {
        return point(this->x * other, this->y * other);
    }

    point operator / (long double other) const
    {
        return point(this->x / other, this->y / other);
    }
};

//Container for line segment
struct segment { point p1, p2; };

//Dot product ab.bc
ld dot(const point& a, const point& b, const point& c)
{
    point AB = b - a;
    point BC = c - b;
    return AB.x*BC.x + AB.y*BC.y;
}

//Cross product
//AB X AC
ld cross(const point& A, const point& B, const point& C)
{
    point AB = B - A, AC = C - A;
    return(AB.x * AC.y - AB.y * AC.x);
}

//Finds orientation of triplet of points p, q, r
//Returns Colinear, CW, or CCW
int orientation(const point& p, const point& q, const point& r)
{
    ld val = cross(p, q, r);
    if(abs(val) < EPSILON) return Colinear;
    return (val > 0) ? CW : CCW;
}

ld dist(const point& p1, const point& p2) {
    return sqrt(pow(p1.x-p2.x,2) + pow(p1.y-p2.y,2));
}

//Checks if point p is possibly on the segment s
//but doesn't guarantee it is
bool onSegment(const point& p, const segment& s)
{
    bool x = (abs(s.p1.x - s.p2.x) < EPSILON && abs(p.x - s.p2.x) < EPSILON) || (p.x <= max(s.p1.x, s.p2.x) && p.x >= min(s.p1.x, s.p2.x));
    bool y = (abs(s.p1.y - s.p2.y) < EPSILON && abs(p.y - s.p2.y) < EPSILON) || (p.y <= max(s.p1.y, s.p2.y) && p.y >= min(s.p1.y, s.p2.y));
    return x && y;
}

//Returns of list of intersection points between segments s1, and s2
//If they do not intersect, the result is an empty vector
//If they intersect at exactly 1 point, the result contains that point
//If they overlap for non-0 distance, the left and right points of that intersection
//  are returned
vector<point> intersect(const segment& s1, const segment& s2)
{
/*
    cout << "Intersect:" << endl;
    cout << s1.p1 << " -> " << s1.p2 << endl;
    cout << s2.p1 << " -> " << s2.p2 << endl;
*/
    point a = s1.p1, b = s1.p2, c = s2.p1, d = s2.p2;

    if(orientation(a, b, c) == Colinear && orientation(a, b, d) == Colinear &&
        orientation(c, d, a) == Colinear && orientation(c, d, b) == Colinear)
    {
        point min_s1 = min(a, b), max_s1 = max(a, b);
        point min_s2 = min(c, d), max_s2 = max(c, d);
/*
        cout << "Colinear" << endl;
        cout << min_s1 << " -> " << max_s1 << endl;
        cout << min_s2 << " -> " << max_s2 << endl;
*/
        if(max_s1 < min_s2 || max_s2 < min_s1) return {};

        point start = max(min_s1, min_s2), end = min(max_s1, max_s2);
        if(start == end)
            return {start};
        else
            return {min(start, end), max(start, end)};
    }

    long double a1 = b.y - a.y, a2 = d.y - c.y;
    long double b1 = a.x - b.x, b2 = c.x - d.x;
    long double c1 = a1*a.x + b1*a.y, c2 = a2*c.x + b2*c.y;
    long double det = a1*b2 - a2*b1;
    if(abs(det) > EPSILON)
    {
        point inter((b2*c1 - b1*c2)/det, (a1*c2 - a2*c1)/det);
        //cout << "Checking " << inter << " vs segments" << endl;
        //cout << onSegment(inter, s1) << " " << onSegment(inter, s2) << endl;
        if(onSegment(inter, s1) && onSegment(inter, s2))
            return {inter};
    }
    return {};
}

//Squared magnitude of point vector
ld sqmag(const point& p1)
{
    return p1.x*p1.x + p1.y*p1.y;
}

//Magnitude of point vector
ld mag(const point& p1)
{
    return sqrt(sqmag(p1));
}

//Scalar projection of vector a onto vector b
ld sproject(const point& a, const point& b)
{
    return dot(a, point(0, 0), b)/mag(b);
}

//Vector projection of vector a onto vector b
point vproject(const point& a, const point& b)
{
    return b * sproject(a, b) / mag(b);
}

//Checks if two segments straddle each other
bool straddle(const segment& s1, const segment& s2)
{
    long double cross1 = cross(s1.p1, s1.p2, s2.p1);
    long double cross2 = cross(s1.p1, s1.p2, s2.p2);

    if((cross1 > 0 && cross2 > 0) ||
       (cross1 < 0 && cross2 < 0)) return false;

    if(abs(cross1) < EPSILON && abs(cross2) < EPSILON &&
       orientation(s1.p2, s2.p1, s2.p2) != Colinear)
       return false;

    return true;
}

//Returns distance from line (or segment) to point
long double linePointDist(const segment& s, const point& p, bool isSegment=false)
{
    if(s.p1 == s.p2)
    {
        if(p == s.p1) return 0;
        return mag(p - s.p1);
    }

    if(isSegment)
    {
        if(dot(s.p1, s.p2, p) > 0) return mag(s.p2 - p);
        if(dot(s.p2, s.p1, p) > 0) return mag(s.p1 - p);
    }
    return abs(cross(s.p1, s.p2, p) / mag(s.p1 - s.p2));
}

void solve(ld r, ld l, ld w, ld a, ld b) {
    r *= 2;
    a = M_PI - a;
    b = M_PI - b;
    r = min(r, l);
    r = min(r, w);

    point topleft = {0,w};
    point topright = {l,w};
    point bottomleft = {0,0};
    point bottomright = {l,0};

    point topdoor = {topright.x+cos(a)*l,topright.y+sin(a)*l};
    point bottomdoor = {bottomright.x+cos(b)*l,bottomright.y+sin(b)*l};

    r = min(r,linePointDist({topright,topdoor},topleft,true));
    r = min(r,linePointDist({topright,topdoor},bottomdoor,true));
    r = min(r,linePointDist({bottomright,bottomdoor},topright,true));
    r = min(r,linePointDist({bottomright,bottomdoor},topdoor,true));
    r = min(r,linePointDist({topright, {10000,w}},bottomdoor,true));

    cout << fixed;
    cout.precision(9);
    cout << r/2 << endl;
}

int main() {
    ld r, l, w;
    cin >> r >> l >> w;

    int cases;
    cin >> cases;
    while(cases--) {
        ld a, b;
        cin >> a >> b;
        solve(r, l, w, a, b);
    }
}
