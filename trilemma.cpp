#include <bits/stdc++.h>

using namespace std;

struct point {
    int x, y;
};

int dist(point p1, point p2) {
    int d1 = (p1.x-p2.x);
    int d2 = (p1.y-p2.y);
    return d1*d1+d2*d2;
}

bool colinear(point p1, point p2, point p3) {
    int a = p1.x * (p2.y - p3.y) +
            p2.x * (p3.y - p1.y) +
            p3.x * (p1.y - p2.y);
    return (a == 0);
}

void solve() {
    point p1, p2, p3;
    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;
    cin >> p3.x >> p3.y;

    if(colinear(p1, p2, p3)) {
        cout << "not a triangle" << endl;
        return;
    }

    vector<int> d;
    d.push_back(dist(p1,p2));
    d.push_back(dist(p3,p2));
    d.push_back(dist(p1,p3));
    sort(d.begin(), d.end());

    bool isoceles = false;
    if(d[0] == d[1] || d[1] == d[2]) {
        isoceles = true;
    }

    if(isoceles) {
        cout << "isosceles ";
    }
    else {
        cout << "scalene ";
    }

    if(d[0] + d[1] == d[2]) {
        cout << "right ";
    }
    if(d[0] + d[1] > d[2]) {
        cout << "acute ";
    }
    if(d[0] + d[1] < d[2]) {
        cout << "obtuse ";
    }

    cout << "triangle" << endl;
}

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
