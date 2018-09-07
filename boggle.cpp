#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> used(4, vector<bool>(4, false));

bool search(vector<vector<char>>& v, string& s, int i, int j, int ch) {
    // Base case
    if(ch == s.size()) {
        return true;
    }

    // Out of range
    if(i < 0 || j < 0 || i == 4 || j == 4) {
        return false;
    }

    // If this spot is already used, quit
    if(used[i][j]) {
        return false;
    }

    // If not matching, quit
    if(v[i][j] != s[ch]) {
        return false;
    }

    // Search surrounding
    for(int x = -1; x <= 1; x++) {
        for(int y = -1; y <= 1; y++) {

            used[i][j] = true;
            bool good = search(v, s, i+x, j+y, ch+1);
            used[i][j] = false;

            if(good) return true;
        }
    }

    return false;
}

bool found(vector<vector<char>>& v, string& s) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(search(v, s, i, j, 0)) return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<string> dict(n);
    for(auto& i : dict) {
        cin >> i;
    }

    vector<int> scores = {0,0,0,1,1,2,3,5,11};

    int q;
    cin >> q;
    while(q--) {
        vector<vector<char>> v;
        v.resize(4, vector<char>(4));
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                cin >> v[i][j];
            }
        }

        int score = 0;
        int total = 0;
        string word = "";

        for(auto& i : dict) {
            if(found(v, i)) {
                total++;
                if(i.length() > word.length()) {
                    word = i;
                }
                if(i.length() == word.length() && i < word) {
                    word = i;
                }
                score += scores[i.length()];
            }
        }

        cout << score << " " << word << " " << total << endl;
    }
}
