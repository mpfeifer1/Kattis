#include <bits/stdc++.h>

using namespace std;

bool w = false;

bool cmp(string s1, string s2) {
    if(s1 == s2) return false;
    map<char,int> vals;
    vals['K'] = 0;
    vals['Q'] = 1;
    vals['R'] = 2;
    vals['B'] = 3;
    vals['N'] = 4;

    if(s1.length() < s2.length()) {
        return false;
    }

    if(s1.length() > s2.length()) {
        return true;
    }

    if(s1.length() == 2) {
        if(s1[1] == s2[1]) {
            return s1[0] < s2[0];
        }
        return w ^ s1[1] < s2[1];
    }

    if(vals[s1[0]] == vals[s2[0]]) {
        if(s1[2] == s2[2]) {
            return s1[1] < s2[1];
        }
        return w ^ s1[2] < s2[2];
    }

    return vals[s1[0]] < vals[s2[0]];
}

int main() {
    vector<vector<char>> v;
    v.resize(17, vector<char>(33));

    for(auto& i : v) {
        for(auto& j : i) {
            cin >> j;
            //cout << j;
        }
        //cout << endl;
    }

    map<int,char> col;
    col[2] = 'a';
    col[6] = 'b';
    col[10] = 'c';
    col[14] = 'd';
    col[18] = 'e';
    col[22] = 'f';
    col[26] = 'g';
    col[30] = 'h';
    map<int,char> row;
    row[1] = '8';
    row[3] = '7';
    row[5] = '6';
    row[7] = '5';
    row[9] = '4';
    row[11] = '3';
    row[13] = '2';
    row[15] = '1';

    vector<string> white;
    vector<string> black;

    for(auto i : row) {
        for(auto j : col) {
            char c = v[i.first][j.first];
            if(c != '.' && c != ':') {
                string s = "";
                if(c != 'p' && c != 'P') {
                    s += toupper(c);
                }
                s += j.second;
                s += i.second;

                if(isupper(c)) {
                    black.push_back(s);
                }
                else {
                    white.push_back(s);
                }
            }
        }
    }

    /*
    for(auto i : white) {
        cout << i << endl;
    }
    cout << endl;
    for(auto i : black) {
        cout << i << endl;
    }
    */


    swap(white,black);

    sort(white.begin(), white.end(), cmp);
    w = true;
    sort(black.begin(), black.end(), cmp);

    cout << "White: ";
    for(int i = 0; i < (int)white.size()-1; i++) {
        cout << white[i] << ",";
    }
    if(white.size() > 0) {
        cout << white.back();
    }
    cout << endl;

    cout << "Black: ";
    for(int i = 0; i < (int)black.size()-1; i++) {
        cout << black[i] << ",";
    }
    if(black.size() > 0) {
        cout << black.back();
    }
    cout << endl;
}
