#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int total = 0;
    int count = 0;
    while(cin >> s) {
        total++;
        for(int i = 0; i < s.size()-1; i++) {
            if(s[i] == 'a' && s[i+1] == 'e') {
                count++;
                break;
            }
        }
    }

    if(total == 0 || double(count) / double(total) >= .4) {
        cout << "dae ae ju traeligt va" << endl;
    }
    else {
        cout << "haer talar vi rikssvenska" << endl;
    }
}
