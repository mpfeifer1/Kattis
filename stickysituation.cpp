#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
    int sticks;
    cin >> sticks;
    vector<ull> s;
    for(int i = 0; i < sticks; i++) {
        ull temp;
        cin >> temp;
        s.push_back(temp);
    }

    sort(s.begin(), s.end());

    for(int i = 0; i < sticks - 2; i++) {
        if(s[i]+s[i+1] > s[i+2]) {
            cout << "possible" << endl;
            return 0;
        }
    }

    cout << "impossible" << endl;
}
