#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;

    int a = 0;
    int b = 0;

    for(int i = 0; i < s.size(); i += 2) {
        if(s[i] == 'A') a += s[i+1]-'0';
        else b += s[i+1]-'0';

        if(a >= 11 && a-b >= 2) {
            cout << "A" << endl;
            return 0;
        }

        if(b >= 11 && b-a >= 2) {
            cout << "B" << endl;
            return 0;
        }
    }
}
