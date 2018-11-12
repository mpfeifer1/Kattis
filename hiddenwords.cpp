#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<char>> v;

vector<int> dx = {0,0,1,-1};
vector<int> dy = {1,-1,0,0};

bool inrange(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m;
}

bool find(int i, int j, vector<vector<bool>>& vis, string& s, int pos) {
    if(pos >= s.size()) return true;
    if(!inrange(i,j)) return false;
    if(v[i][j] != s[pos]) return false;

    if(vis[i][j]) return false;
    vis[i][j] = true;

    for(int k = 0; k < 4; k++) {
        if(find(i+dx[k],j+dy[k],vis,s,pos+1)) return true;
    }

    vis[i][j] = false;

    return false;
}

bool solve(string& s) {
    vector<vector<bool>> vis;
    vis.resize(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(find(i, j, vis, s, 0)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    unordered_set<char> chars;

    v.resize(n, vector<char>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> v[i][j];
            chars.insert(v[i][j]);
        }
    }

    int ans = 0;
    unordered_map<string,bool> strings;

    int q;
    cin >> q;
    while(q--) {
        string s;
        cin >> s;

        bool skip = false;
        for(auto i : s) {
            if(!chars.count(i)) {
                skip = true;
                break;
            }
        }
        if(skip) continue;

        if(strings.count(s) == 0) {
            strings[s] = solve(s);
        }

        if(strings[s]) ans++;
    }

    cout << ans << endl;
}
