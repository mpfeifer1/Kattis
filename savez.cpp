#include <bits/stdc++.h>

using namespace std;

struct trie {
    int ends = 0;
    map<pair<char,char>, trie> m;
};

int insert(string& s, trie& t, int pos, int val) {
    if(pos == s.size()) {
        t.ends = max(t.ends + 1, val + 1);
        return t.ends;
    }

    char c1 = s[pos];
    char c2 = s[s.size()-pos-1];

    t.ends = max(t.ends, val);
    return insert(s, t.m[{c1,c2}], pos+1, t.ends);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    trie t;
    int best = 0;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        best = max(best, insert(s,t,0,0));
    }

    cout << best << endl;
}
