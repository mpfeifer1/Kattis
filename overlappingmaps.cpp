#include <bits/stdc++.h>
using namespace std;

int w, h, x, y, s, r;

double getdist(double bigX, double bigY) {
    double smallX = (s/100.0)*bigX;
    double smallY = (s/100.0)*bigY;

    double tempR = sqrt(smallX*smallX + smallY*smallY);
    double theta = atan2(bigY, bigX);

    theta += r*2*M_PI/360.0;

    smallX = cos(theta)*tempR + x;
    smallY = sin(theta)*tempR + y;

    double dist = sqrt(pow(bigX-smallX,2) + pow(bigY-smallY,2));
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(2) << fixed;

    while(cin >> w >> h >> x >> y >> s >> r) {
        if(!(w||h||x||y||s||r)) break;

        double minx = 0, maxx = w;
        double miny = 0, maxy = h;

        while(maxx - minx > .0000001) {
            double scalex = maxx - minx;
            double scaley = maxy - miny;

            double lx = scalex * .25 + minx;
            double hx = scalex * .75 + minx;
            double ly = scaley * .25 + miny;
            double hy = scaley * .75 + miny;

            double d1 = getdist(lx,ly);
            double d2 = getdist(hx,ly);
            double d3 = getdist(lx,hy);
            double d4 = getdist(hx,hy);

            double avgx = (minx + maxx) / 2;
            double avgy = (miny + maxy) / 2;

            if(d1 < d2 && d1 < d3 && d1 < d4) {
                maxx = avgx;
                maxy = avgy;
            }
            if(d2 < d1 && d2 < d3 && d2 < d4) {
                minx = avgx;
                maxy = avgy;
            }
            if(d3 < d2 && d3 < d1 && d3 < d4) {
                maxx = avgx;
                miny = avgy;
            }
            if(d4 < d2 && d4 < d3 && d4 < d1) {
                minx = avgx;
                miny = avgy;
            }
        }

        cout << minx << " " << miny << endl;
    }
}
