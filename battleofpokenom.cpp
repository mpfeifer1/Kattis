#include <bits/stdc++.h>

using namespace std;

pair<char,int> finds(int n, vector<vector<char>> v) {
    vector<int> e(2,0);
    for(int i = 0; i < n*2; i++) {
        // If this attack is super effective, count it
        if(v[i/2][i%2] == 'E') {
            e[i%2]++;
        }

        int attempts0 = n - (i/2) - 1;
        int attempts1 = n - (i/2);

        // If player 1 secured a win
        if(e[0] > e[1] + attempts1) {
            return {'1',i+1};
        }

        // If player 2 secured a win
        if(e[0] + attempts0 < e[1]) {
            return {'2',i+1};
        }
    }

    // If it's a tie
    return {'T',n*2};
}

int findc(int n, int s, char w, vector<vector<char>> v) {
    if(w == 'T') {
        return s-3;
    }

    int known = 0;
    for(int i = 0; i < s; i++) {
        char actual = v[i/2][i%2];
        char expect;
        if((i%2 == 1) ^ (w == '1')) {
            expect = 'E';
        }
        else {
            expect = 'N';
        }

        if(actual != expect) known = i+1;
    }

    return known;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> v(n,vector<char>(2));
    for(auto& i : v) {
        cin >> i[0] >> i[1];
    }

    // Find S
    pair<int,int> s = finds(n,v);

    // Find C
    int c = findc(n,s.second,s.first,v);

    cout << s.second << " " << c << endl;
}

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        solve();
    }
}
