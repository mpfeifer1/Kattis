#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> v;
    v.resize(m, vector<char>(n));

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    vector<string> words;

    string word = "";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(v[i][j] == '#') {
                words.push_back(word);
                word = "";
            }
            else {
                word.push_back(v[i][j]);
            }
        }
        words.push_back(word);
        word = "";
    }

    word = "";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[j][i] == '#') {
                words.push_back(word);
                word = "";
            }
            else {
                word.push_back(v[j][i]);
            }
        }
        words.push_back(word);
        word = "";
    }

    vector<string> ok;
    for(auto a : words) {
        if(a.length() > 1) {
            ok.push_back(a);
        }
    }

    sort(ok.begin(), ok.end());

    cout << ok[0] << endl;
}
