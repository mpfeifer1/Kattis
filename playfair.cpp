#include <bits/stdc++.h>

using namespace std;

int main() {
    string cipher;
    string message;

    getline(cin, cipher);
    getline(cin, message);

    map<char,pair<int,int>> m;
    map<pair<int,int>,char> rev;
    int x = 0;
    int y = 0;
    for(auto i : cipher) {
        if(i == ' ') {
            continue;
        }
        if(m.count(i) == 0) {
            rev[{x,y}] = i;
            m[i] = {x,y};
            y++;
            if(y >= 5) {
                x++;
                y = 0;
            }
        }
    }
    for(char i = 'a'; i <= 'z'; i++) {
        if(i == 'q') {
            continue;
        }
        if(m.count(i) == 0) {
            rev[{x,y}] = i;
            m[i] = {x,y};
            y++;
            if(y >= 5) {
                x++;
                y = 0;
            }
        }
    }

    string nospaces;
    for(auto i : message) {
        if(i != ' ') {
            nospaces.push_back(i);
        }
    }

    string actual;
    int idx = 0;
    for(int i = 0; i < nospaces.size(); i++) {
        if(idx%2==1 && actual[idx-1] == nospaces[i]) {
            actual.push_back('x');
            idx++;
        }
        actual.push_back(nospaces[i]);
        idx++;
    }

    string answer;
    int n = actual.size();
    for(int i = 0; i < n; i+=2) {
        char c1 = actual[i];
        char c2;
        if(i == n-1) {
            c2 = 'x';
        }
        else {
            c2 = actual[i+1];
        }

        if(c1 == c2) {
            c2 = 'x';
        }

        int x1 = m[c1].first;
        int y1 = m[c1].second;
        int x2 = m[c2].first;
        int y2 = m[c2].second;
        if(m[c1].first == m[c2].first) {
            answer += rev[{x1, (y1+1)%5}];
            answer += rev[{x2, (y2+1)%5}];
        }
        else if(m[c1].second == m[c2].second) {
            answer += rev[{(x1+1)%5, y1}];
            answer += rev[{(x2+1)%5, y2}];
        }
        else {
            answer += rev[{x1,y2}];
            answer += rev[{x2,y1}];
        }
    }

    for(auto i : answer) {
        cout << (char)toupper(i);
    }
    cout << endl;
}
