#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    bool Left = false;
    for(char c : s) Left |= (c=='L');
    if(!Left) {
        for(int i = 1; i <= n; ++i) {
            cout << i << ' ';
        }
        cout << '\n';
        return 0;
    }
    vector<pair<char, int> > arr;//letter, cnt
    char prev = s[0];
    int cnt = 1;
    for(int i = 1; i < s.size(); ++i) {
        if(s[i] == prev) {
            cnt++;
        } else {
            arr.push_back({prev, cnt});
            cnt = 1;
            prev = s[i];
        }
    }
    arr.push_back({prev, cnt});
    int nextAvailable = 1;
    for(int j = 0; j < arr.size(); ++j) {
        auto p = arr[j];
        //cout << "\nhere: " << p.first << ' ' << p.second << '\n';
        if(p.first == 'L') {
            for(int i = nextAvailable+p.second; i >= nextAvailable; --i) {
                cout << i << ' ';
            }
            nextAvailable += p.second+1;
        } else {
            if(j > 0 && j+1 < arr.size()) p.second--;
            for(int i = nextAvailable, cnt = 0; cnt < p.second; ++cnt, ++i) {
                cout << i << ' ';
            }
            nextAvailable += p.second;
        }
        //now have one right left, need to jump
        //if(j+1 < s.size()) arr[j+1].second++;
    }
    cout << '\n';
    return 0;
}
