#include <bits/stdc++.h>

using namespace std;

struct question {
    bool ac = false;
    int time = 0;
};

int main() {
    map<char,question> m;
    int t;
    while(cin >> t && t != -1) {
        char q;
        string s;
        cin >> q >> s;

        if(s == "right") {
            m[q].ac = true;
            m[q].time += t;
        }
        else {
            m[q].time += 20;
        }
    }

    int rights = 0;
    int total = 0;
    for(auto i : m) {
        if(i.second.ac) {
            rights++;
            total += i.second.time;
        }
    }

    cout << rights << " " << total << endl;
}
