#include <bits/stdc++.h>

using namespace std;

int l, w;

bool inrange(int x, int y) {
    return x >= 0 && y >= 0 && x < w && y < l;
}

struct car {
    int offset;
    int interval;
    int speed;
    bool goingleft;
};

bool squished(int x, int t, car c) {
    if(c.goingleft) {
        x = w - x - 1;
    }

    t--;

    // Get where the first car was
    int actualpos = c.offset;
    actualpos += (t * c.speed);

    // Now there should be cars 'interval' apart
    while(actualpos < w) {
        actualpos += c.interval;
    }
    while(actualpos >= x) {
        actualpos -= c.interval;
    }

    // If it's stopped, check this pos
    if(c.speed == 0) {
        if(x == actualpos + c.interval) return true;
        return false;
    }

    // Otherwise, check where it will be
    int loextra = min(1, c.speed);
    int hiextra = c.speed;
    if(actualpos + loextra <= x && x <= actualpos + hiextra) {
        return true;
    }
    return false;
}

int main() {
    cin >> l >> w;

    vector<car> v;
    for(int i = 0; i < l; i++) {
        car c;
        cin >> c.offset >> c.interval >> c.speed;
        c.goingleft = (i%2 == 1);
        v.push_back(c);
    }

    int x, y;
    cin >> x;
    y = -1;

    bool safe = true;

    string s;
    cin >> s;
    int t = 0;
    for(auto i : s) {
        t++;
        if(i == 'L') {
            x--;
        }
        if(i == 'R') {
            x++;
        }
        if(i == 'U') {
            y++;
        }
        if(i == 'D') {
            y--;
        }

        if(y >= l) {
            break;
        }

        if(inrange(x, y)) {
            if(squished(x, t, v[l-y-1])) {
                safe = false;
            }
        }
    }

    if(y < l) safe = false;

    if(safe) {
        cout << "safe" << endl;
    }
    else {
        cout << "squish" << endl;
    }
}
