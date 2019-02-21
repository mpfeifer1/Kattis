#include <bits/stdc++.h>
using namespace std;

const int N = 1002;
string prefix[N], sufix[N];
int len[N];

inline string revInv(string s) {
    for(int i = 0, bound = s.size()/2; i < bound; ++i) {
        swap(s[i], s[s.size()-i-1]);
    }
    //reverse(s.begin(), s.end());
    for(char &c : s) {
        c = 'L' + 'R' - c;
    }
    return s;
}


unordered_map<string, int> memo[N];

bool solve(int n, string s) {
    if(n == 1) return s == "L";
    if(memo[n].count(s)) return memo[n][s];
    if(s.size() > len[n]) return memo[n][s] = false;
    if(solve(n-1, s)) return memo[n][s] = true;
    if(solve(n-1, revInv(s))) return memo[n][s] = true;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == 'L') {
            string pre = "", suf = "";
            if(i) {
                pre = s.substr(0, i);
            }
            if(i+1 < s.size()) {
                suf = s.substr(i+1);
            }
            if(pre == "" || (pre.size() <= sufix[n-1].size() && pre == sufix[n-1].substr((int)sufix[n-1].size()-(int)pre.size()))) {
                if(suf == "" || (suf.size() <= prefix[n-1].size() && suf == revInv(sufix[n-1]).substr(0, suf.size()))) {
                    return memo[n][s] = true;
                }
            }
        }
    }
    return memo[n][s] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    prefix[1] = sufix[1] = "L";
    len[1] = 1;
    for(int i = 2; i < N; ++i) {
        len[i] = min(100, 2*len[i-1] + 1);
        if(prefix[i-1].size() >= 1000) {
            prefix[i] = prefix[i-1];
            sufix[i] = sufix[i-1];
        } else {
            prefix[i] = prefix[i-1] + "L" + revInv(prefix[i-1]);
            sufix[i] = sufix[i-1] + "L" + revInv(sufix[i-1]);
            if(prefix[i].size() > 1000) {
                prefix[i].resize(1000);
                reverse(sufix[i].begin(), sufix[i].end());
                sufix[i].resize(1000);
                reverse(sufix[i].begin(), sufix[i].end());
            }
        }
    }
    int ID = 1;
    while(t--) {
        cout << "Case " << ID++ << ": ";
        int n;
        string s;
        cin >> n >> s;
        if(solve(n, s)) {
            cout << "Yes\n";
        } else cout << "No\n";
    }
}
