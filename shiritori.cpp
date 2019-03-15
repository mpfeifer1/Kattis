#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    string c;
    cin >> c;

    set<string> s;
    s.insert(c);

    for(int i = 0; i < n-1; i++) {
        string t;
        cin >> t;

        if(s.count(t)) {
            cout << "Player " << ((i+1)%2)+1 << " lost" << endl;
            return 0;
        }
        s.insert(t);
        if(c.back() != t.front()) {
            cout << "Player " << ((i+1)%2)+1 << " lost" << endl;
            return 0;
        }

        c = t;
    }

    cout << "Fair Game" << endl;
}
