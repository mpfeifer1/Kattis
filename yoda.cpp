#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    while(s1.size() < s2.size()) {
        s1.push_back('0');
    }
    while(s1.size() > s2.size()) {
        s2.push_back('0');
    }

    string t1, t2;

    for(int i = 0; i < s1.length(); i++) {
        if(s1[i] >= s2[i]) {
            t1.push_back(s1[i]);
        }
        if(s2[i] >= s1[i]) {
            t2.push_back(s2[i]);
        }
    }

    while(t1[t1.length()-1] == '0' && t1.length() > 1) {
        t1.pop_back();
    }
    while(t2[t2.length()-1] == '0' && t2.length() > 1) {
        t2.pop_back();
    }

    reverse(t1.begin(), t1.end());
    reverse(t2.begin(), t2.end());

    if(t1.length() > 0) {
        cout << t1 << endl;
    }
    else {
        cout << "YODA" << endl;
    }

    if(t2.length() > 0) {
        cout << t2 << endl;
    }
    else {
        cout << "YODA" << endl;
    }
}
