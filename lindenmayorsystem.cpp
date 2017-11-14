#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    unordered_map<char, string> translate;
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;
        cin.ignore(4);
        string s;
        cin >> s;
        translate[c] = s;
    }

    string s, e;
    cin >> e;

    for(int i = 0; i < m; i++) {
        s = e;
        e = "";
        for(auto j : s) {
            if(translate.count(j) > 0) {
                e += translate[j];
            }
            else {
                e += j;
            }
        }
    }

    cout << e << endl;
}
