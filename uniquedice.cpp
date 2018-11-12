#include <bits/stdc++.h>

using namespace std;

string up(string s) {
    int t = s[0];
    s[0] = s[2];
    s[2] = s[1];
    s[1] = s[3];
    s[3] = t;
    return s;
}

string ri(string s) {
    int t = s[2];
    s[2] = s[5];
    s[5] = s[3];
    s[3] = s[4];
    s[4] = t;
    return s;
}

string fr(string s) {
    int t = s[0];
    s[0] = s[5];
    s[5] = s[1];
    s[1] = s[4];
    s[4] = t;
    return s;
}

string re(string s) {
    unordered_set<string> v;

    queue<string> q;
    q.push(s);
    while(!q.empty()) {
        string curr = q.front();
        q.pop();

        if(v.count(curr)) continue;
        v.insert(curr);

        q.push(ri(curr));
        q.push(up(curr));
        q.push(fr(curr));
    }

    string best = "999999";
    for(auto& i : v) {
        best = min(best, i);
    }
    return best;
}

int main() {
    int n;
    cin >> n;

    unordered_map<string,int> m;
    for(int i = 0; i < n; i++) {
        string s = "      ";
        for(auto& j : s) {
            cin >> j;
        }

        s = re(s);
        m[s]++;
    }

    int best = 1;
    for(auto i : m) {
        best = max(best, i.second);
    }

    cout << best << endl;
}
