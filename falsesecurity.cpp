#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int getIndex(string& s, vector<string>& v) {
    for(int i = 0; i < v.size(); i++) {
        if(v[i] == s) {
            return i;
        }
    }
    return -1;
}

int getIndex(char& c, vector<char>& v) {
    for(int i = 0; i < v.size(); i++) {
        if(v[i] == c) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<char> v1 = {'A',
        'B',
        'C',
        'D',
        'E',
        'F',
        'G',
        'H',
        'I',
        'J',
        'K',
        'L',
        'M',
        'N',
        'O',
        'P',
        'Q',
        'R',
        'S',
        'T',
        'U',
        'V',
        'W',
        'X',
        'Y',
        'Z',
        '_',
        ',',
        '.',
        '?'};
    vector<string> v2 = {".-",
        "-...",
        "-.-.",
        "-..",
        ".",
        "..-.",
        "--.",
        "....",
        "..",
        ".---",
        "-.-",
        ".-..",
        "--",
        "-.",
        "---",
        ".--.",
        "--.-",
        ".-.",
        "...",
        "-",
        "..-",
        "...-",
        ".--",
        "-..-",
        "-.--",
        "--..",
        "..--",
        ".-.-",
        "---.",
        "----"};

    string s;
    while(getline(cin, s)) {
        vector<int> len;
        string morse;
        string ans;

        for(auto c : s) {
            int index = getIndex(c, v1);
            string item = v2[index];
            morse += item;
            len.push_back(item.length());
        }

        reverse(len.begin(), len.end());

        int n = 0;
        for(int i = 0; i < len.size(); i++) {
            string m = morse.substr(n, len[i]);
            ans += v1[getIndex(m, v2)];
            n += len[i];
        }

        cout << ans << endl;
    }
}
