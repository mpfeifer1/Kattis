#include <bits/stdc++.h>

using namespace std;

int main() {
    int cases;
    cin >> cases;
    for(int casenum = 0; casenum < cases; casenum++) {
        string s1, s2;
        cin >> s1 >> s2;

        int a = 0;
        int b = 0;
        int c = 0;
        int d = 0;
        int e = 0;
        int f = 0;

        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] == '0' && s2[i] == '0') a++;
            if(s1[i] == '0' && s2[i] == '1') b++;
            if(s1[i] == '1' && s2[i] == '0') c++;
            if(s1[i] == '1' && s2[i] == '1') d++;
            if(s1[i] == '?' && s2[i] == '0') e++;
            if(s1[i] == '?' && s2[i] == '1') f++;
        }

        int ans = 0;
        ans = min(b,c);
        b -= ans;
        c -= ans;

        if(b > 0) {
            ans += b + e + f;
        }
        else {
            if(f < c) {
                ans = -1;
            }
            else {
                ans += c;
                e -= c;

                ans += c;
                ans += e+f;
            }
        }

        cout << "Case " << casenum+1 << ": " << ans << endl;
    }
}

