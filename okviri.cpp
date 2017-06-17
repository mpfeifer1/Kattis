#include <iostream>
#include <vector>
#include <string>

using namespace std;

void addframe(vector<string>& v, char c) {
    v[0] += "..#.";
    v[1] += ".#.#";
    v[2] += "#." + string(1,c) + ".";
    v[3] += ".#.#";
    v[4] += "..#.";
}

void addend(vector<string>& v) {
    v[0] += ".";
    v[1] += ".";
    v[2] += "#";
    v[3] += ".";
    v[4] += ".";
}

void convert(vector<string>& v, int i) {
    v[0][i+2] = '*';
    v[1][i+1] = '*';
    v[1][i+3] = '*';
    v[2][i+0] = '*';
    v[2][i+4] = '*';
    v[3][i+1] = '*';
    v[3][i+3] = '*';
    v[4][i+2] = '*';
}

int main() {
    string s;
    cin >> s;

    vector<string> v;
    v.resize(5);

    // Build initial pattern
    for(auto c : s) {
        addframe(v, c);
    }
    addend(v);

    // Convert to stars
    for(int i = 0; i < s.size(); i++) {
        if(i % 3 == 2) {
            convert(v, 4 * i);
        }
    }

    // Print answer
    for(auto str : v) {
        cout << str << endl;
    }
}
