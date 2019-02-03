#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    list<char> l;
    for(auto i : s) {
        l.push_back(i);
    }

    auto it = l.begin();
    it++;

    int parity = 0;

    while(l.size() > 2 && next(it) != l.end()) {
        if(*prev(it) != *next(it)) {
            it = l.erase(it);
            parity++;
            if(prev(it) != l.begin()) {
                it = prev(it);
            }
            if(prev(it) != l.begin()) {
                it = prev(it);
            }
        }
        else {
            it = next(it);
        }
    }

    if(parity % 2 == 0) {
        cout << "Bash" << endl;
    }
    else {
        cout << "Chikapu" << endl;
    }
}

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        solve();
    }
}
