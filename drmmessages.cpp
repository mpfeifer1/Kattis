#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    string beg = s.substr(0, s.length()/2);
    string end = s.substr(s.length()/2);

    vector<int> b, e;
    for(auto i : beg) {
        b.push_back(i - 'A');
    }
    for(auto i : end) {
        e.push_back(i - 'A');
    }

    int rot1 = 0;
    for(auto i : e) {
        rot1 += i;
    }
    rot1 %= 26;
    for(auto& i : e) {
        i += rot1;
        i %= 26;
    }

    int rot2 = 0;
    for(auto i : b) {
        rot2 += i;
    }
    rot2 %= 26;
    for(auto& i : b) {
        i += rot2;
        i %= 26;
    }

    for(int i = 0; i < b.size(); i++) {
        b[i] += e[i];
        b[i] %= 26;
        cout << char(b[i] + 'A');
    }
    cout << endl;
}
