#include <bits/stdc++.h>

using namespace std;

int n;

bool process(vector<char>& currcol, vector<int>& col) {
    sort(col.begin(),col.end());
    sort(currcol.begin(),currcol.end());

    bool works = true;
    for(int i = 0; i < n; i++) {
        if(currcol[i] == '(') col[i]++;
        else col[i]--;
        if(col[i] < 0) works = false;
    }

    return works;
}

int main() {
    cin >> n;

    vector<vector<char>> v(n,vector<char>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    vector<int> col(n,0);

    bool works = true;
    for(int i = 0; i < n; i++) {
        vector<char> currcol;
        for(int j = 0; j < n; j++) {
            currcol.push_back(v[j][i]);
        }
        if(!process(currcol,col)) {
            works = false;
            break;
        }
    }

    for(int i = 0; i < col.size(); i++) {
        if(col[i] != 0) {
            works = false;
            break;
        }
    }

    if(works) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
