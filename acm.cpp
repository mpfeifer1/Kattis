#include <bits/stdc++.h>

using namespace std;

struct question {
    int wrongs;
    bool ac;
    int time;
};

int main() {
    map<char,question> m;
    int t;
    while(cin >> t && t != -1) {
        char q;
        string s;
        cin >> q >> s;

        if(m[1].ac) {
            continue;
        }
        else {
            if(s == "right") {
                m[q].ac = true;
                m[q].time = t;
            }
            else {
                m[q].wrongs++;
            }
        }

    }

    int rights = 0;
    int total = 0;
    for(auto i : m) {
        if(i.second.ac) {
            rights++;
            total += i.second.time + i.second.wrongs*20;
        }
    }

    cout << rights << " " << total << endl;
}
