#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define eps 0.0000001

struct event {
    bool pill;
    ld time;
    ll x, y;
    ld slope, yInt;
    ld prevSlope, prevYInt;
};

bool operator< (const event &lhs, const event &rhs) {
    return lhs.time > rhs.time;
}

int main() {
    ll n, p, c;
    cin >> n >> p >> c;
    priority_queue<event> q;
    ll t, x, y;
    for(int i = 0; i < p; ++i) {
        cin >> t >> x >> y;
        event temp;
        temp.time = t;
        temp.x = x;
        temp.y = y;
        temp.pill = true;
        q.push(temp);
    }
    ld topSlope = -1;
    ld topYInt = n;
    while(!q.empty()) {
        event curr = q.top();
        q.pop();

        if(curr.pill) {
            //cout << "pill: " << curr.time << ' ' << curr.x << ' ' << curr.y << '\n';
            ld yCordinate = topSlope*curr.time + topYInt;
            yCordinate -= c;

            ld newSlope = -curr.y/(ld)curr.x;

            yCordinate -= newSlope*curr.time;

            event temp;
            temp.pill = false;
            temp.slope = newSlope;
            temp.yInt = yCordinate;

            temp.prevSlope = topSlope;
            temp.prevYInt = topYInt;

            temp.time = -(yCordinate - topYInt) / (newSlope - topSlope);

            if(temp.slope*temp.time + temp.yInt <= 0) {
                continue;
            }

            //cout << "here1\n";
            //cout << "times: " << curr.time << ' ' << temp.time << '\n';
            if(temp.time > curr.time) {
                //cout << "pushing line: " << temp.slope << ' ' << temp.yInt << '\n';
                q.push(temp);
            }

        } else {//line
            //cout << "line: " << curr.slope << ' ' << curr.yInt << '\n';
            if(topSlope == curr.prevSlope && topYInt == curr.prevYInt) {//replace
                topSlope = curr.slope;
                topYInt = curr.yInt;
            } else {

                event temp;
                temp.pill = false;
                temp.slope = curr.slope;
                temp.yInt = curr.yInt;

                temp.prevSlope = topSlope;
                temp.prevYInt = topYInt;

                temp.time = -(curr.yInt - topYInt) / (curr.slope - topSlope);

                if(temp.slope*temp.time + temp.yInt <= 0) {
                    continue;
                }
                //cout << "here2\n";
                if(temp.time > curr.time) {
                    //cout << "pushing line: " << temp.slope << ' ' << temp.yInt << '\n';
                    q.push(temp);
                }
            }
        }
    }
    cout << setprecision(8) << fixed << -topYInt/topSlope << '\n';
    return 0;
}

