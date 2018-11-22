#include <bits/stdc++.h>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if((s1 == "OCT" && s2 == "31") || (s1 == "DEC" && s2 == "25")) {
        cout << "yup" << endl;
    }
    else {
        cout << "nope" << endl;
    }
}
