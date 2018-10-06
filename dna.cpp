#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int moves = 0;
    bool wanta = true;
    for(int i = n-1; i >= 0; i--) {
        if(wanta && s[i] == 'A') continue;
        if(!wanta && s[i] == 'B') continue;

        if(i == 0) {
            moves++;
            continue;
        }

        moves++;

        if(wanta) {
            if(s[i-1] != 'A') {
                wanta = false;
            }
        }
        else {
            if(s[i-1] != 'B') {
                wanta = true;
            }
        }
    }

    cout << moves << endl;
}
