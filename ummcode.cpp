#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    string s;
    string t;
    while(cin >> s) {
        bool good = true;
        string a;
        for(auto i : s) {
            if(isalpha(i)) {
                a.push_back(i);
            }
        }
        s = a;
        for(auto i : s) {
            if(i != 'u' && i != 'm') {
                good = false;
            }
        }
        if(good) t += s;
    }

    vector<int> v(t.size()/7,0);
    for(int i = 0; i < t.size(); i++) {
        if(t[i] == 'u')
        v[i/7] += pow(2,7-(i%7)-1);
    }

    for(auto i : v) {
        cout << char(i);
    }
    cout << endl;
}
