#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> dx = {1,2,2,1,-1,-2,-2,-1};
vector<int> dy = {-2,-1,1,2,2,1,-1,-2};

bool inrange(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < n;
}

bool dfs(vector<vector<char>>& v, int i, int j, int pos, string& s) {
    if(pos == s.size()) {
        return true;
    }

    for(int k = 0; k < 8; k++) {
        int nexti = i + dx[k];
        int nextj = j + dy[k];

        if(!inrange(nexti,nextj)) continue;

        if(v[nexti][nextj] == s[pos]) {
            if(dfs(v,nexti,nextj,pos+1,s)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    cin >> n;

    vector<vector<char>> v(n, vector<char>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    string target = "ICPCASIASG";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dfs(v,i,j,0,target)) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;
}
