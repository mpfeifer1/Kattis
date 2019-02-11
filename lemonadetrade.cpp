#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
ld eps = 0.00000001;

int main() {
    int n;
    cin >> n;

    unordered_map<string,ld> m;
    m.reserve(100000);
    m["pink"] = 0;

    for(int i = 0; i < n; i++) {
        string s1, s2;
        ld d;
        cin >> s1 >> s2 >> d;

        ld newval = -100000-10;
        ld oldval = -100000-10;
        if(m.count(s2)) {
            newval = m[s2] + log2l(d);
        }
        if(m.count(s1)) {
            oldval = m[s1];
        }

        if(abs(oldval - newval) < eps) continue;
        m[s1] = max(oldval,newval);
    }

    cout << fixed;
    cout.precision(8);

    if(m.count("blue") == 0) {
        cout << 0.0 << endl;
    }
    else {
        cout << min(pow(ld(2),min(ld(4),m["blue"])),ld(10)) << endl;
    }
}
