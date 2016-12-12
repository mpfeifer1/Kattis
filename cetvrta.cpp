#include <bits/stdc++.h>

using namespace std;

int getOutlier(int a, int b, int c) {
    if(a == b) {
        return c;
    }
    if(b == c) {
        return a;
    }
    return b;
}

int main() {
    int x1,x2,x3,y1,y2,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cout << getOutlier(x1,x2,x3) << " " << getOutlier(y1,y2,y3) << endl;
}
