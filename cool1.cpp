#include <bits/stdc++.h>

using namespace std;
int inf= 1 << 30;

bool same(string s, int k) {
    vector<char> m(k);
    for(int i = 0; i < k; i++) {
        m[i] = s[i];
    }
    for(int i = 0; i < s.size(); i++) {
        if(m[i%k] != s[i]) {
            return false;
        }
    }
    return true;
}

string compress(string s) {
    for(int i = s.size(); i >= 1; i--) {
        if(s.size() % i == 0) {
            if(same(s, s.size()/i)) {
                return s.substr(0, s.size()/i);
            }
        }
    }
    return s;
}

pair<int,int> getnext(vector<vector<char>>& board, pair<int,int> curr, char op) {
    pair<int,int> next = curr;
    if(op == '^') {
        next.first--;
    }
    if(op == 'v') {
        next.first++;
    }
    if(op == '<') {
        next.second--;
    }
    if(op == '>') {
        next.second++;
    }

    if(board[next.first][next.second] == '#') {
        return curr;
    }
    else {
        return next;
    }
}

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;
    s = compress(s);

    int t;
    pair<int,int> curr;
    vector<vector<char>> v(n, vector<char>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
            if(v[i][j] == 'R') {
                curr.first = i;
                curr.second = j;
                v[i][j] = '.';
            }
        }
    }

    vector<vector<vector<int>>> vis;
    vis.resize(n, vector<vector<int>>(n, vector<int>(s.size(), inf)));

    deque<pair<int,char>> ops;

    while(vis[curr.first][curr.second][t % s.size()] == inf) {
        vis[curr.first][curr.second][t % s.size()] = t;
        pair<int,int> next = getnext(v, curr, s[t % s.size()]);
        if(next != curr) {
            ops.push_back({t,s[t%s.size()]});
        }
        t++;
        curr = next;
    }

    int lo = vis[curr.first][curr.second][t % s.size()];
    while(!ops.empty() && ops.front().first < lo) {
        ops.pop_front();
    }

    string actual;
    for(auto i : ops) {
        actual.push_back(i.second);
    }

    actual = compress(actual);

    if(actual.size() <= 0) {
        cout << 1 << endl;
    }
    else {
        cout << actual.size() << endl;
    }
}
