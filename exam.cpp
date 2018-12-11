#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    int s=0, d=0;
    for(int i = 0; i < s1.size(); i++) {
        if(s1[i] == s2[i]) s++;
        else d++;
    }

    int swaps = s1.size() - n;
    int lo = min(swaps, d);
    d -= lo;
    swaps -= lo;
    s += lo;

    cout << s - swaps << endl;
}
