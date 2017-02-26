#include <iostream>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    while(!s1.empty() && !s2.empty() && s1[0] == s2[0]) {
        s1.erase(0,1);
        s2.erase(0,1);
    }

    int l1 = s1.length() - 1;
    int l2 = s2.length() - 1;

    while(!s1.empty() && !s2.empty() && s1[l1] == s2[l2]) {
        s1.erase(l1,1);
        s2.erase(l2,1);
        l1--;
        l2--;
    }

    cout << s2.length() << endl;
}
