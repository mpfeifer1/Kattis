#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void check(string s, string& best, int i, int j) {
    reverse(s.begin(), s.begin()+i);
    reverse(s.begin()+i, s.begin()+j);
    reverse(s.begin()+j, s.end());

    if(s < best) {
        best = s;
    }
}

int main() {
    string s;
    cin >> s;

    string best = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    for(int i = 1; i < s.size()-1; i++) {
        for(int j = i + 1; j < s.size()-0; j++) {
            check(s, best, i, j);
        }
    }

    cout << best << endl;
}
