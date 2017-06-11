#include <iostream>
#include <vector>
#include <string>

using namespace std;

void check(int from, int to, vector<vector<bool>>& v) {
    for(int j = 0; j < 26; j++) {
        if(v[j][from]) {
            bool c = v[j][to];
            v[j][to] = true;
            if(!c) {
                check(j, to, v);
            }
        }
        if(v[to][j]) {
            bool c = v[from][j];
            v[from][j] = true;
            if(!c) {
                check(from, j, v);
            }
        }
    }
}

int main() {
    int chars, words;
    cin >> chars >> words;

    vector<vector<bool>> v;

    v.resize(26, vector<bool>(26, false));

    for(int i = 0; i < 26; i++) {
        v[i][i] = true;
    }

    for(int i = 0; i < chars; i++) {
        char from, to;
        cin >> from >> to;

        from -= 'a';
        to   -= 'a';

        bool c = v[from][to];

        v[from][to] = true;

        if(!c) {
            check(from, to, v);
        }
    }

    for(int i = 0; i < words; i++) {
        bool works = true;

        string old, now;
        cin >> old >> now;

        if(old.length() != now.length()) {
            cout << "no" << endl;
            continue;
        }

        for(int j = 0; j < old.length(); j++) {
            if(v[old[j]-'a'][now[j]-'a']) {

            }
            else {
                works = false;
            }
        }

        if(works) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }
}
